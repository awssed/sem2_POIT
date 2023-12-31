#include<iostream>
using namespace std;

struct node//��������� �������� ���� ������������ �� ������ ������������ ������
{
    int elem;//�������������� ����
    node* sled;//��������� ��� ��������� ������� ����
};
class Spisok//
{
private:
    node* ld, * rd;//��������� ������ � ����� ����� ����
    int el_left, el_right;//��������� ��������� ��� �������� � ������ � ����������� ����� � ����� �������
public:
    void POSTROENIE();//������� ���������� ����
    void VYVOD();//������� ������ ����� ����
    void VSTAV1(int);//������� ���������� ����� �����
    void VSTAV2(int);//������� ���������� ����� �����
    int SetElLeft() { return el_left; }// ������ ������������ ����������� ����� ����� ��� ���������� ������ � ���
    int SetElRight() { return el_right; }// ������ ������������ ����������� ����� ����� ��� ���������� ������ � ���
    void YDALE1();//������� �������� ����� �����
    void YDALE2();//������� �������� ����� �����
    void OCHISTKA();//������� ������ ������� ����
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;//���������� ���� ���� spisok ������� ��� �������� ����
    int el;//���������� �������� ���������� ��� ������� ����� � ���

    A.POSTROENIE(); A.VYVOD();//����� ������� ���������� ����� ���� � ��� ������ �����
    cout << "������� ����� ������.\n";
    cout << "������� ������� ������������ �����: ";
    cin >> el;//������������� �������� ���������� ��� ���������� � ������ ���� ����
    A.VSTAV1(el); A.VYVOD();//����� ������� ������� � ������ ���� ���� � ������ ����� ����
    cout << "������� ����� �����.\n";
    cout << "������� ������� ������������ �����: ";
    cin >> el;//������������� �������� ��������� ��� ������ ����� �����
    A.VSTAV2(el); A.VYVOD();//����� ������� ������ ����� � ������ ����� ����
    cout << "������ ����� ������.\n";
    A.YDALE1(); A.VYVOD(); //����� ������� �������� ������ ����� � ������ ����� ����
    cout << A.SetElRight() << endl;//����� ������������ ������� �����
    cout << "������ ������ �����.\n";
    A.YDALE2(); A.VYVOD();//����� ������� �������� ����� ����� � ����� ����� ����
    cout << A.SetElLeft() << endl;//����� ������������ ������� �����
    A.OCHISTKA();//������ ������� ����

    cout << "\n";
    system("PAUSE");
}

void Spisok::POSTROENIE()
//���������� ���� :
// ld - ��������� �� ����� ����� ����,
// rd - ��������� �� ������ ����� ����.
{
    node* k;//���������� ��������� �� ����� ����
    int el;//�������� ��������� ��� ������� � �������������� ���� ����

    cout << "������� ���������� ������� ����: \n";
    cin >> el;//������������� �������� ����������
    if (el != 0)//���� �� ����� ������ ���� ����� ��������� ���
    {
        k = new (node);//��������� ������ ��� ������ ����� ����
        (*k).elem = el;//��������� ��������������� ���� �����
        (*k).sled = NULL;//��������� ������� ��������� ����� ����� ��������� �� ����, �.� ����� ��� ���� ������ �������
        ld = k;rd = k;//��������� �� ����� � ������ ���� ���� ����� ���� ��� ��������� �� ����� ������ �������� ������� ����, �.� �� ������������
        cin >> el;//���� ������ �������� ����� �����
        while (el != 0)//���� ��������� ������� �� ����� ����� ���� ����� ��������� ������ � ������ ����� ����
        {
            VSTAV1(el); cin >> el;//������� ��������� � ������ ����� ����
        }
    }
    else
    {
        rd = NULL; ld = NULL;//���� ������ ��������� ������� ���� ����� ����� ���� �� ��������� ������ � ����� ��������� �� ����
    }
}

void Spisok::VYVOD()
//����� ����������� ����:
// ld - ��������� �� ����� ����� ����.
{
    node* k;//��������� ����� ���� � ������� ����� ��������� ���������� ������ ����� ���� � �������� ���

    k = ld; //��������� ��������� k �� ����� ����� ����
    cout << "���: ";
    while (k != NULL)//���� �� ��������� �������� �������� ����� ������ ������ ����
    {
        cout << (*k).elem << " "; //������ ��������������� ���� ����� ����
        k = (*k).sled;//������� ��������� k �� ��������� ������� ����
    }
    cout << endl;
}

void Spisok::VSTAV1(int el)
// ��������� �����, ����������� ������� el, � ��� ������.
// ld - ��������� �� ����� ����� ����,
// rd - ��������� �� ������ ����� ����.
{
    node* k;//���������� ����� ����� ������� ��������� �������� ������ ���� ����

    k = new (node);//��������� ������ ��� ������ �����
    (*k).elem = el; //���������� ���� ����
    (*k).sled = NULL;//������������ ��������� �� ��������� ������� ������ ����� ���� ,�.� �� ����� ����� ������ ����� ��������� ����� ��������� � ����������� ������ 
    if (rd != NULL)//���� ������ ��������� �� ����� ����
    {
        (*rd).sled = k; //�������������� ������ ��������� �� ����� ����������� �������
        rd = k;// ������������� �������� ������ ��������� �� ��������� ������ ����������� �����
    }
    else//� ������ ������ ����������� ������� � ���� ����� ��������� ������������
    {
        rd = k; ld = k;//��������� �� ����� � ������ ���� ���� ����� ���� ��� ��������� �� ����� ������ �������� ������� ����, �.� �� ������������
    }
}

void Spisok::VSTAV2(int el)
//��������� �����, ����������� ������� el, � ��� �����.
// ld - ��������� �� ����� ����� ����,
// rd - ��������� �� ������ ����� ����.
{
    node* k;//���������� ����� ������ �����

    k = new (node);//��������� ������ ��� ������ ������ �����
    (*k).elem = el; //���������� ��������������� ���� ������ �����
    (*k).sled = ld;//���������� ��������� ������ ����� ��������� �� ���
    if (ld != NULL) ld = k;//���� ��� �� ������ ��������� �� ��������������� �������� ����� ��������� �� ����� ����� ����������� �������
    else { ld = k; rd = k; }////��������� �� ����� � ������ ���� ���� ����� ���� ��� ��������� �� ����� ������ �������� ������� ����, �.� �� ������������
}

void Spisok::YDALE1()
//�������� ����� �� ���� ������
//� ����������� ���������� ����� � ���������� el_right.
// ld - ��������� �� ����� ����� ����,
// rd - ��������� �� ������ ����� ����.
{
    node* z;//��������� ��������� �� ������� �����
    node* k;//��������� ��������� ����������� ������� �� ���� �����

    if (rd == ld)//���� � ��� ���� ����� �� ��������� �� ����� � ����� ����� ���� ����� �����
    {
        el_right = (*rd).elem; //���������� ���������� ����� � ���������� el_right.
        delete rd;//�������� �� ������ �����
        ld = rd = NULL; //������������ ���������� �� ������ � ����� ����� ���� ����
        cout << "��� ����!\n";
    }
    else//���� � ��� ��� ����� ������ ������ �����
    {
        z = ld; //������������� ��������� �� ������� �������
        k = (*ld).sled;//������������� ����������� ���������
        while (k != rd)//���� ���������� ��������� �� ��������� ������� �����
        {
            z = k; //������� ��������� �� �������� ��������� �����
            k = (*k).sled;//���������� �������� ��������� �� ��������� �����
        }
        el_right = (*rd).elem; //���������� ���������� ����� � ���������� el_right.
        (*z).sled = NULL; //������������� ��������� ��� ��������� ������� �������� ����� �� ����, �.� �� ������ ���������
        delete rd;//��������� ������ ���������� �����
        rd = z;//���������� �������� �� ������ ����� �� ���������� �����
    }
}

void Spisok::YDALE2()
// �������� ����� �� ���� �����
// � ����������� ���������� ����� � ���������� el_left.
// ld - ��������� �� ����� ����� ����,
// rd - ��������� �� ������ ����� ����.
{
    node* q;//��������� ��������� �� ������� ����� � ����

    if (ld != NULL)//���� ��� �� ������
    {
        el_left = (*ld).elem;//���������� ���������� ����� � ���������� el_left.
        q = ld;//������ ������� ��������� �� ����� ����� ����
        ld = (*ld).sled; //���������� ��������� �� ����� ����� �� ���� �� ��������� �����
        delete q;//��������� ������ ����������� ��������� ����� ������
    }
    else  cout << "��� ����!\n";
}

void Spisok::OCHISTKA()
{
    node* k, * q;//���������� �������� � ������������ �� ���� ����� ���������

    k = ld;//������� ��������� ����� ����� �������� �� ����� ����� �����
    if (k != NULL)//���� �� ��������� �������� �����
    {
        q = (*k).sled;//������������� �� ��������� �� k ����� ��������� ���������
        while (q != NULL)//���� ����������� ��������� �� ��������� ����
        {
            delete k;//����������� ������ ����� �� ������� ��������� ������� ���������
            k = q; //����������� �������� �������� �� ��������� �����
            q = (*k).sled;//����������� ����������� ��������� �� ��������� �����
        }
        delete k;//���������� ������ ���������� ����� ��������� ���������� ������
    }
}
