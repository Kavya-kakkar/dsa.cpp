#include<iostream>
#include<climits>
using namespace std;
//bool linearSearch(int mat[][3],int rows,int cols,int key) {
//    for(int i=0;i<rows;i++) {
//        for(int j=0;j<cols;j++) {
//            if(mat[i][j] == key) {
//                return true;
//            }
//        }
//    }
//}
int getMaxSum(int mat[][3],int rows,int cols) {
    int maxRowSum = INT_MIN;

    for(int i=0;i<rows;i++) {
        int rowSum = 0;
        for(int j=0;j<cols;j++) {
            rowSum += mat[i][j];

        }
        maxRowSum = max(maxRowSum,rowSum);
    }
    return maxRowSum;

}
int main() {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;
    cout<<getMaxSum(matrix,rows,cols)<<endl;
    //for(int i=0;i<rows;i++) {
    //    for(int j=0;j<cols;j++) {
     //       cout<<matrix[i][j]<<" ";
       // }
       // cout<<endl;
    //}
    //cout<<endl;
    return 0;
}
