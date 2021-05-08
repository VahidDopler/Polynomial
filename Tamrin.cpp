#include <iostream>
#include <vector>
#include <ostream>
#include <stdio.h>
#include <cmath>
using namespace std;
class polynomial
{
private:
    int Coefficient;
    int power;
public:
    polynomial();
    ~polynomial();
    friend ostream& operator<<(ostream&, polynomial&);
    friend istream& operator>>(istream&, polynomial&);
    void change_Coefficient();
    void change_power();
    polynomial operator=(const polynomial &);
    int get_Coefficient() { return Coefficient;}
    int get_power() { return power;}
    int operator+(const polynomial &);
    int operator-(const polynomial &);
    void operator*(const polynomial &);
    void operator+=(const polynomial &);
    void operator*=(const polynomial &);
    void operator <(const polynomial &);
    void operator <=(const polynomial &);
    void operator ==(const polynomial &);
};

void polynomial:: operator<=(const polynomial &obj)
{
    if (power > obj.power)
        cout << "The first sentence is bigger or equal " << endl;
    else
        cout << "The second sentence is bigger " << endl;
}

void polynomial:: operator<(const polynomial &obj)
{
    if (power > obj.power)
        cout << "The first sentence is bigger " << endl;
    else
        cout << "The second sentence is bigger " << endl;
}


void polynomial:: operator==(const polynomial &obj)
{
    if ((obj.Coefficient == Coefficient) && (obj.power == power))
        cout << "These two sentences are equal ";
    else
        cerr << "These two sentences are not equal ";
}

void polynomial::operator+=(const polynomial &obj)
{
    polynomial oa;
    oa.Coefficient=Coefficient+obj.Coefficient;
    oa.power=obj.power;
    Coefficient=oa.Coefficient;
    power=oa.power;
}

void polynomial::operator*=(const polynomial &obj)
{
    polynomial oa;
    oa.Coefficient=Coefficient*obj.Coefficient;
    oa.power=power+obj.power;
    Coefficient=oa.Coefficient;
    power=oa.power;
}

void polynomial::operator*(const polynomial &obj)
{
    cout << endl << "The result is " << (Coefficient*obj.Coefficient) << "x^" << (power+obj.power);
}

int polynomial::operator-(const polynomial &obj)
{
    return (Coefficient - obj.Coefficient);
}

int polynomial::operator+(const polynomial &obj)
{
    return (Coefficient + obj.Coefficient);
}

polynomial polynomial::operator=(const polynomial &obj)
{
    Coefficient=obj.Coefficient;
    power=obj.power;
    return *this;
}

void polynomial::change_power()
{
    int num=0;
    cout << endl << "Enter your number to change power => ";
    cin >> num;
    power=num;
}

void polynomial:: change_Coefficient()
{
    int num=0;
    cout << endl << "Enter your number to change Cofficient => ";
    cin >> num;
    Coefficient=num;
}

polynomial::polynomial()
{
    Coefficient=0;
    power=0;
}

polynomial::~polynomial()
{
    //cout << "The proccess is Done ";
}

istream& operator>>(istream& input, polynomial& obj )
{
    cout<<"\nEnter an integer number for Coefficient =>  ";
    input>> obj.Coefficient;
    cout<<"\nEnter an integer number for power => ";
    input >> obj.power;
    return input;
}

ostream& operator<<(ostream& output,polynomial& oa)
{
    output<<"\nCoefficient:"<< oa.Coefficient;
    output<<"\npower:"<< oa.power << endl;
    return output;
}

void input_proccess(vector<polynomial> &vect , int size)
{
    for (size_t i = 0; i < size; i++)
    {
        polynomial obj;
        cin >> obj;
        vect.push_back(obj);
    }
}

void output_proccess(vector<polynomial> &vect )
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        cout << vect[i];
        cout << endl;
    }
}

void change_information(vector <polynomial> &vect)
{
    int number=0 , selector=0 , number_selector=0;
    cout << endl << "Whick corrcet number you want to change (Enter number) => ";
    cin >> number_selector;  
    cout << "What in formatin you want to change :" << endl;
    cout << "Enter 1 to change Coefficient and 2 to chnage power => ";
    cin >> selector;
    switch (selector)
    {
    case 1:
        vect[number_selector-1].change_Coefficient();
        break;
    case 2:
        vect[number_selector-1].change_power();
    default:
        break;
    } 
}

void Assignmenti(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet_number => ";
    cin >> place1;
    cout << "Enter your first corrcet_number => ";
    cin >> place2;
    vect[(place1)-1]=vect[(place2)-1];
}

// An optimized version of Bubble Sort
void bubbleSort(vector<polynomial> &vect)
{
   int i, j , temp1=0 , temp2=0 , n=vect.size()-1;
   for (int i = n; i >= 0; i--)
   {
       for (int j = n; j > n - i; j--)
        {
            temp1=vect[j].get_power();
            temp2=vect[j - 1].get_power();
                if ( temp1 > temp2 )
                    swap(vect[j], vect[j-1]);
        }   
   }
}

void delete_specific_element(vector<polynomial> &vect)
{
    int selected=0;
    cout << "Enter your corrcet-number you want delete => ";
    cin >> selected;
    vect.erase(vect.begin()+(selected-1));
    cout << "The proccess of delete is done !" << endl;
}

void summon(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    if (vect[place1-1].get_power() == vect[place2-1].get_power())
    {
        cout << endl << vect[place1-1]+vect[place2-1] << "x^" << vect[place1-1].get_power();
    }
    else
        cerr << "The powers are not equal ";
}

void subtraction (vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    if (vect[place1-1].get_power() == vect[place2-1].get_power())
    {
        cout << endl << vect[place1-1]-vect[place2-1] << "x^" << vect[place1-1].get_power();
    }
    else
        cerr << "The powers are not equal ";
}

void multiply (vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    vect[place1-1]*vect[place2-1];
}

void multiply_and_assignment (vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    vect[place1-1]*=vect[place2-1];
}

void summon_and_assignment(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    if (vect[place1-1].get_power() == vect[place2-1].get_power())
    {
       vect[place1-1]+=vect[place2-1];
    }
    else
        cerr << "The powers are not equal ";
}

void compare1(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    vect[place1-1]==vect[place2-1];
}

void compare2(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    vect[place1-1]<vect[place2-1];
}

void compare3(vector<polynomial> &vect)
{
    int place1=0 , place2=0;
    cout << "Enter your first corrcet-number => ";
    cin >> place1;
    cout << "Enter your second correct-number => ";
    cin >> place2;
    vect[place1-1]<=vect[place2-1];
}

void calculate(vector<polynomial> &vect)
{
    int temp=0 , result=0 , x=0;
    cout << "Enter your correct-number shomare => ";
    cin >> temp;
    cout << "Enter your number you want to put and calculate => ";
    cin >> x;
    cout << "The result is " << (vect[temp-1].get_Coefficient()*pow(x,vect[temp-1].get_power()));
}

int main()
{
    int temp=0;
    cout << "Enter the number of correct sentences => ";
    cin >> temp;
    vector<polynomial>array;
    input_proccess (array , temp);
    change_information(array);
    change_information(array);
    Assignmenti(array);
    output_proccess (array );
    bubbleSort(array);
    delete_specific_element(array);
    summon(array);
    subtraction(array);
    multiply(array);
    multiply_and_assignment(array);
    summon_and_assignment(array);
    compare1(array);
    compare2(array);
    compare3(array);
    output_proccess (array );
    calculate(array);
}