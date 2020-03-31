//13.2 面向对象
//类名 对象名表

#include <iostream>
#include <string.h>
using namespace std;

//定义一个坐标系中的圆类，对圆可以求面积和周长。
/*圆的属性有圆心坐标和半径，而对圆的操作给出的求面积和周长的功能之外
还应能够设置一个圆的属性及输出这些属性的值。
*/
class Circle
{
private:  //私有访问权限，数据成员或成员函数的说明
    double x, y, r;
public:   //公有访问权限，成员函数或数据成员的说明
    void set(double x1, double y1, double r1);//set 设置数据成员值
   /* {
        x = x1; y = y1; r = r1; //类体中不允许对数据成员初始化
    }*/
        void print();
    /*{
        cout << "圆心:(" << x << "," << y << ")" << "半径：" << r << endl;
    }*/
        double getarea();
    /*{
        return 3.14 * r * r;
    }*/
        double getgirth();
    /*{
        return 2 * 3.14 * r;
    }*/
//protected:  保护访问权限，成员函数或数据成员的说明
};

void Circle::set(double x1, double y1, double r1)
{
    x = x1; y = y1; r = r1;
}

void Circle::print()
{
    cout << "圆心:(" << x << "," << y << ")" << "半径：" << r << endl;
}

double Circle::getarea()
{
    return 3.14 * r * r;
}

double Circle::getgirth()
{
    return 2 * 3.14 * r;
}

//定义一个职工类Staff,包含工号和工资两个数据成员及设置和输出职工信息的功能；
//同时通过对象和指针对该类进行测试
class Staff
{
private:
    char no[7];
    float wage;
public:
    void display()
    {
        cout << no << ":" << wage << endl;
    }
    void set(const char n[], float w)   //考虑通用性，工号宜通过字符串表达，故可以定义为字符串组或字符指针类型
    {
        strcpy_s(no, n);
        wage = w;
    }
};

int main()
{
    Circle c;
    c.set(0, 0, 2);
    c.print();
    cout << c.getarea() << endl;
    cout << c.getgirth() << endl;

    Staff s, * s1;
    s.set("110109",3526);
    s.display();
    s1 = new Staff;
    s1->set("090304", 4003); //通过对象指针测试类的功能时，对象指针像其他指针一样，需要先赋值再使用
    s1->display();
    system("pause");
    return 0;
}
