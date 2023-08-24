#include <iostream>
#include <vector>

using namespace std;

int *gpVect = NULL;
int gnCount = 0;
int gnMax = 0;

struct Vector {
  int *m_pVect, m_nCount, m_nMax, m_nDelta;
};

void Resize(Vector *pThis) {
  pThis->m_pVect = new int[pThis->m_nMax + pThis->m_nDelta];
  pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem) {
  if (pThis->m_nCount == pThis->m_nMax)
    Resize(pThis);
  pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
  Vector *vc = new Vector;
  vc->m_pVect = gpVect;
  vc->m_nCount = gnCount;
  vc->m_nMax = gnMax;
  vc->m_nDelta = 10;
  for (int i = 0; i < 100; i++) {
    Insert(vc, i);
    std::cout << vc->m_pVect[i] << " ";
  }
}