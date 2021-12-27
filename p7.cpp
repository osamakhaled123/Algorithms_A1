#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,choice,rot;
    double X_Trans,Y_Trans,X_Scal,Y_Scal,X,Y,degree;
    cout << "Enter the number of Vertices: " << endl;
    cin >>n ;
    double mat [n][3];
    for (int i =0; i<n; i++)
    {
        cout  << "please enter your vertex no." << i+1 << " coordinates: "<<endl;
        cin >> X  >>Y;
        mat [i][0]= X;
        mat [i][1]= Y;
        mat [i][2]= 1;
    }
    cout <<"============"<<endl <<"Your vertices values now:"<<endl;
    for (int i =0; i<n; i++)
    {
        cout  << mat [i][0] << " " << mat [i][1] << " " <<  mat [i][2] <<endl;
    }
    cout <<"============"<<endl;
    do
    {
        cout << "Please choose the operation you want to execute: " << endl;
        cout << "[1] Vertex Translation" <<endl <<"[2] Vertex Scaling"<<endl;
        cout << "[3] Vertex Rotation" <<endl <<"[0] EXIT"<<endl;
        cin >> choice ;
        if (choice == 1)
        {
            for (int i =0; i<n; i++)
            {
                cout << "Please enter X' and Y' (the coordinates you will translate your vertex no."<<i+1 <<" with): " << endl;
                cin >> X_Trans  >>  Y_Trans ;
                mat [i][0]+= X_Trans;
                mat [i][1]+= Y_Trans;
                mat [i][2]= 1.0;
            }
            cout <<"============"<<endl <<"Your vertices values now:"<<endl;
            for (int i =0; i<n; i++)
            {
                cout  << mat [i][0] << " " << mat [i][1] << " " <<  mat [i][2] <<endl;
            }
            cout <<"============"<<endl;
        }
        else if (choice == 2)
        {
            for (int i =0; i<n; i++)
            {
                cout << "Please enter a and b (the values you will scale your vertex no."<<i+1 <<" with): " << endl;
                cin >> X_Scal  >>  Y_Scal ;
                mat [i][0]*= X_Scal;
                mat [i][1]*= Y_Scal;
                mat [i][2]= 1.0;
            }
            cout <<"============"<<endl <<"Your vertices values now:"<<endl;
            for (int i =0; i<n; i++)
            {
                cout  << mat [i][0] << " " << mat [i][1] << " " << mat [i][2] <<endl;
            }
            cout <<"============"<<endl;
        }
        else if (choice == 3)
        {
            cout << "Enter the degree you are rotating your vertices with:"<<endl;
            cin >> degree;
            degree =  (M_PI *  degree)/180;
            double rotationMatrixClockwise[3][3] = {{cos(degree), -sin(degree), 0},
                {sin(degree), cos(degree),  0},
                {0,           0,            1}
            };
            double rotationMatrixAntiClockwise[3][3] = {{cos(degree),  sin(degree), 0},
                {-sin(degree), cos(degree), 0},
                {0,            0,           1}
            };
            cout << "choose the rotation you want to perform"<<endl;
            cout << "[1]clockwise rotation"<<endl<< "[2]anticlockwise rotation"<<endl;
            cin >>rot;
            if (rot == 1)
            {
                for (int i=0 ;i<n;i++){
                for (int j=0 ;j<n;j++){
                for (int k=0 ;k<n;k++){
                        mat[i][j]+=  mat[i][k]*rotationMatrixClockwise[k][j];
                }
                }
                }
            cout <<"============"<<endl <<"Your vertices values now:"<<endl;
            for (int i =0; i<n; i++)
            {
                cout  << mat [i][0] << " " << mat [i][1] << " " << mat [i][2] <<endl;
            }
            cout <<"============"<<endl;
            } else if (rot == 2)
            {
                for (int i=0 ;i<n;i++){
                for (int j=0 ;j<n;j++){
                for (int k=0 ;k<n;k++){
                        mat[i][j]+=  mat[i][k]*rotationMatrixClockwise[k][j];
                }
                }
                }
            cout <<"============"<<endl <<"Your vertices values now:"<<endl;
            for (int i =0; i<n; i++)
            {
                cout  << mat [i][0] << " " << mat [i][1] << " " << mat [i][2] <<endl;
            }
            cout <<"============"<<endl;
            }else
            {
                cout << "please enter a valid rotation choice "<<endl;
            }

        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid choice " << endl;
        }
    }
    while (choice != 0);
}
