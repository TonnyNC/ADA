#include <iostream>
#include <vector>

using namespace std;

int *gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

class CVector {
private:
  int *m_pVect, m_nCount, m_nMax, m_nDelta;
  void Init(int delta);
  void Resize();

public:
  CVector(int delta = 10);
  void Insert(int elem);
  int getV(int elem);
};

CVector::CVector(int delta) {
  m_nDelta = delta;
  m_nCount = 0;
  m_nMax = delta;
  m_pVect = new int[m_nMax];
}

void CVector::Resize() {
  m_nMax += m_nDelta;
  int *newVect = new int[m_nMax];
  for (int i = 0; i < m_nCount; i++) {
    newVect[i] = m_pVect[i];
  }
  delete[] m_pVect;
  m_pVect = newVect;
}

int CVector::getV(int index) {
  if (index >= 0 && index < m_nCount) {
    return m_pVect[index];
  }
  return -1;
}

void CVector::Insert(int elem) {
  if (m_nCount == m_nMax)
    Resize();
  m_pVect[m_nCount++] = elem;
}

int main() {
  CVector cv;
  for (int i = 0; i < 100; i++) {
    cv.Insert(i);
    std::cout << cv.getV(i) << " ";
  }
}