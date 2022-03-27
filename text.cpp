#include <iostream> 
using namespace std;


//隐式转换 - 从int转换为double
void conversionOne()
{
    int num_int = 9; 
    double num_double; 

    num_double = num_int;

    cout << "num_int : " << num_int <<endl ; 
    cout << "num_double : " << num_double << endl ; 
}

//隐式转换 - 从double转换为int
void conversionTwo()
{ 
    double num_double = 99.9; 
    int num_int; 

    num_int = num_double; 
    
    cout << "num_double : " << num_double <<endl ; 
    cout << "num_int : " << num_int <<endl ; 
}

//显式转换 - c风格转换
void conversionThree()
{   
    double num_double = 26.66;
    int num_int; 

    num_int = (int)num_double; 
    
    cout << "num_double : " << num_double <<endl ; 
    cout << "num_int : " << num_int <<endl ; 
}

//显式转换 - 函数样式转换
void conversionFour()
{   
    double num_double = 26.66;
    int num_int; 

    num_int = int(num_double); 
    
    cout << "num_double : " << num_double <<endl ; 
    cout << "num_int : " << num_int <<endl ; 
}

//显式转换 - static_cast 关键字
void conversionFive()
{   
    double num_double = 26.66;
    int num_int; 

    num_int = static_cast<int>(num_double);
    
    cout << "num_double : " << num_double <<endl ; 
    cout << "num_int : " << num_int <<endl ; 
}

//显式转换 - const_cast 关键字
void conversionSix()
{   
    //const_cast 比较好理解，它用来去掉表达式的 const 修饰或 volatile 修饰。
    //换句话说，const_cast 就是用来将 const/volatile 类型转换为非 const/volatile 类型。

    const int n = 100;
    int *p = const_cast<int*>(&n);
    *p = 234;
    cout<<"n = "<<n<<endl;
    cout<<"*p = "<<*p<<endl;
}

//显式转换 - reinterpret_cast 关键字
void conversionSeven()
{   
    // reinterpret 是“重新解释”的意思 reinterpret_cast 这种转换仅仅是对二进制位的重新解释，不会借助已有的转换规则对数据进行调整，非常简单粗暴，所以风险很高。
    // reinterpret_cast 可以认为是 static_cast 的一种补充，
    // 一些 static_cast 不能完成的转换，就可以用 reinterpret_cast 来完成

    //将 char* 转换为 float*
    char str[]= "http://c.biancheng.net";
    float *p1 =  reinterpret_cast<float*>(str);
    cout<<*p1<<endl;
    //将 int 转换为 int*
    int *p = reinterpret_cast<int*>(100);
 
}

int main()
{
    // conversionOne();
    // conversionTwo();
    // conversionThree();
    // conversionFour();
    // conversionFive();
    // conversionSix();
    // conversionSeven();

    
    

    
 
}
