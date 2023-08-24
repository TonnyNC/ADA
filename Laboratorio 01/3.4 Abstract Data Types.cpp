#include <iostream>
#include <vector>

using namespace std;

int *gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

template <typename Type> class CVector {
private:
  Type *m_pVect;
  int m_nCount, m_nMax, m_nDelta;
  void Init(int delta);
  void Resize();

public:
  CVector(int delta = 10);
  void Insert(Type &elem);
  Type getV(int elem);
};

template <typename Type> CVector<Type>::CVector(int delta) {
  m_nDelta = delta;
  m_nCount = 0;
  m_nMax = delta;
  m_pVect = new int[m_nMax];
}

template <typename Type> void CVector<Type>::Insert(Type &elem) {
  if (m_nCount == m_nMax)
    Resize();
  m_pVect[m_nCount++] = elem;
}

template <typename Type> Type CVector<Type>::getV(int elem) {
  if (elem >= 0 && elem < m_nCount) {
    return m_pVect[elem];
  }

  return Type();
}

template <typename Type> void CVector<Type>::Resize() {
  m_nMax += m_nDelta;
  Type *newVect = new Type[m_nMax];
  for (int i = 0; i < m_nCount; i++) {
    newVect[i] = m_pVect[i];
  }
  delete[] m_pVect;
  m_pVect = newVect;
}

int main() {
  CVector<int> cv;
  for (int i = 0; i < 100; i++) {
    cv.Insert(i);
    std::cout << cv.getV(i) << " ";
  }
}