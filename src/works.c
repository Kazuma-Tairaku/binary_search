#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x) {
    int sum = 0;     //���̐l�̎d����
    int h = 0;      //���l�ڂ�
    int i = 0;

    while (h < k && i < n) {
        if (sum + A[i] <= x) {      //�d���ǉ�
            sum = sum + A[i];
            i++;
        }
        else {      //���̐l
            sum = 0;
            h++;
        }
    }
    return i == n;

}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;

  while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (p(mid)) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }

  printf("%d\n", ub);


  return 0;
}
