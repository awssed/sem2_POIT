
#include <iostream>
using namespace std;

struct node//��������� ����� ���������� ���������������� ������
{
    int elem;//�������������� ����
    node* sled;//��������� �� ��������� �����
    node* pred;//��������� �� ���������� ����� 
};

class Spisok //����� ���������� �������(������) � ���������� ��� ������ � ���������� ���������� �������
{
private:
    node* nsp;//��������� �� ��������� �����
public:
    Spisok() { nsp = NULL; }//��������� ����� � ������ ����� ���� �.� ������ ������� ����� ���������
    void BuiltRing(); //���������� ���������������� ���������� ������ nsp � ��������� ��������� ������.*nsp - ��������� �� ��������� ����� ������
    void VyvodLeftRight();// ����� ����������� ���������������� ���������� ������� ��������� ��������� ������ "�� ������� �������".*nsp - ��������� �� ��������� ����� ������.
    void VyvodRightLeft();// ����� ����������� ���������������� ���������� ������ � ��������� ��������� ������ "������ ������� �������".nsp - ��������� �� ��������� ����� ������.
    void InsAfter(node*, int);// ���������� � ��������� ��������������� ������ ������ �������������� ����� el �����  �����, ��  ������� ��������� ������ Res.
    void InsBefore(node*, int);// ������� � ��������� ��������������� ������ ����� � �������������� ����� el ����� ������, ��  ������� ��������� ������ Res. nsp - ��������� �� ��������� ����� ������.
    void Delete(node*);// �������� �� ���������� ���������������� ������ �����, �� ������� ��������� ������ Res.nsp - ��������� �� ��������� ����� ������.
    void DelAfter(node*);//�������� �� ���������� ���������������� ������ �����,��������������  �����  �����, ��  �������  ��������������� Res.nsp - ��������� �� ��������� ����� ������.
    node* SearchRing(int); //����� �������� el � ��������� ��������������� ������ � ��������� ��������� ������.nsp - ��������� �� ��������� ����� ������.
    void Ochistka();//������ �������� ������
};

void main()
{
    setlocale(LC_ALL, "Rus");
    Spisok A;//���������� ���������� ������
    node* Res;//�������� ����� ������
    int el, el1;//�������� ���������� ��� ���������� ������ �� �������

    A.BuiltRing();//������ ������
    cout << "���������� ������ '�� ������� �������': \n";
    A.VyvodLeftRight();//���������� ������ '�� ������� �������
    cout << "���������� ������'������ ������� �������': \n";
    A.VyvodRightLeft();//���������� ������'������ ������� �������
    cout << "������� ������� �����, ����� �������� ";
    cout << "�������������� �������: ";
    cin >> el;//������� ����� �������� ����� �������
    cout << "������� ������� ������������ �����: ";
    cin >> el1;//���� ����������� ��������
    Res = A.SearchRing(el);//����� ����� ����� �������� ����� �������
    if (Res != NULL)//���� ����� ������� �� ���������� �������
    {
        A.InsAfter(Res, el1);//������� ����� �������� el
        A.VyvodLeftRight();//����� �� ������� �������
    }
    else  cout << "����� � ����� ��������� � ������ ���!\n";
    cout << "������� ������� �����, ����� ������� ";
    cout << "�������������� �������: ";
    cin >> el;//������� ����� ������� ����� �������
    cout << "������� ������� ������������ �����: ";
    cin >> el1;//���� ����������� ��������
    Res = A.SearchRing(el);//����� ����� ����� ������� ����� �������
    if (Res != NULL)//���� ����� ������� ���������� �������
    {
        A.InsBefore(Res, el1);//������� ����� ���������
        A.VyvodLeftRight();//����� �� ������� �������
    }
    else  cout << "����� � ����� ��������� � ������ ���!\n";

    cout << "������� ������� �����, ������� ";
    cout << "���� �������: ";
    cin >> el;//������� ������� ����� �������
    Res = A.SearchRing(el);//����� ����� ������� ����� �������
    if (Res != NULL)//���� ����� ������� �� ������� ���
    {
        A.Delete(Res);//�������� ����� res
        A.VyvodLeftRight();//����� �� ������� �������
    }
    else  cout << "����� � ����� ��������� � ������ ���!\n";

    cout << "������� ������� �����, ����� �������� ";
    cout << "�������������� ��������: ";
    cin >> el;//���� �������� ����� ������� ����� ��������
    Res = A.SearchRing(el);//����� �������� ����� �������� ����� �������� 
    if (Res != NULL)//���� ������� ������ �� ������� ����� ����� ����
    {
        A.DelAfter(Res);//�������� ���������� ����� ����� res
        A.VyvodLeftRight();//����� ������ �� ������� �������
    }
    else  cout << "����� � ����� ��������� � ������ ���!\n";
    A.Ochistka();//��������� ������� ������

    cout << "\n";
    system("PAUSE");
}

void Spisok::BuiltRing()
// ���������� ���������������� ���������� ������ nsp
//          � ��������� ��������� ������.
// nsp - ��������� �� ��������� ����� ������.
{
    node* r;//���������� ����� ������
    int el;//���������� ��� ���������� ��������������� ���� ����� ������
    //�������� ��������� ����� ���������� ������.
    nsp = new(node);//�������� ������ ��� ���������
    r = nsp;//������ ������ ����� �� ���������
    (*nsp).pred = NULL; //������ ��������� �� ���������� �� ���� �� ����� ������������
    (*nsp).sled = NULL;//������ ��������� �� ��������� �� ���� �� ����� ������������
    cout << "������� �������� ������: \n";
    cin >> el;//������ �������� �����
    while (el != 0)//���� �� ����� ��� ���� ����� ��������� ������
    {
        (*r).sled = new (node);//��������� ������ ��� ���������� �����
        (*((*r).sled)).pred = r;//������ ��������� pred ���������� ����� �� ���������� �����
        r = (*r).sled;//��������� ��������� r �� ��������� �����
        (*r).sled = NULL;//������ ���� ��� ��������� sled �� ���� , �� �� ���� ��� ���������
        (*r).elem = el;//��������� �������������� ���� �����
        cin >> el;//������ �������� �����
    }
    //� ������ - �������� ��������� ������!
    if ((*nsp).sled != NULL)//���� ������ �� ������
    {
        (*((*nsp).sled)).pred = r;//������ �������� pred ��������� �� ��c������ �������
        (*r).sled = (*nsp).sled;//������ ��������� next ���������� �������� �� ���������
    }
    else
        cout << "��������� ������ ����!\n";
}

void Spisok::VyvodLeftRight()
// ����� ����������� ���������������� ���������� ������
// � ��������� ��������� ������ "�� ������� �������".
// nsp - ��������� �� ��������� ����� ������.
{
    node* r;//��������� �� ���� ����� ������ � ������� ������� �� ����� ������ �� ������

    cout << "��������� ������: ";
    if ((*nsp).sled != NULL)//���� ������ �� ������
    {
        cout << (*((*nsp).sled)).elem << " ";//������� ������ ������� ������ ��������� �� ����������
        r = (*((*nsp).sled)).sled;//��������� ��������� r �� ��������� �����
        while (r != (*nsp).sled)//���� �� ��������� ����� �� ������� ��������� ��������� ������� ��������
        {
            cout << (*r).elem << " "; //����� ��������
            r = (*r).sled;//������� � ���������� ��������� ������
        }
        cout << endl;//������� �� ����� ������
    }
    else cout << "����!";
}

void Spisok::VyvodRightLeft()
// ����� ����������� ���������������� ���������� ������
// � ��������� ��������� ������ "������ ������� �������".
// nsp - ��������� �� ��������� ����� ������.
{
    node* r;//��������� �� ���� ����� ������ � ������� ������� �� ����� ������ �� ������

    cout << "��������� ������: ";
    if ((*nsp).sled != NULL)//���� ������ �� ������ 
    {
        cout << (*((*((*nsp).sled)).pred)).elem << " ";//����� ������ ����������� ��������
        r = (*((*((*nsp).sled)).pred)).pred;//������ �������� �� ���������� �� ��������� ���������
        while (r != (*((*nsp).sled)).pred)//���� �� ��������� ����� �� ������� ��������� ���������
        {
            cout << (*r).elem << " "; //����� ��������
            r = (*r).pred;//������� � ����������� �����
        }
        cout << endl;//������� � ���������� �����
    }
    else cout << "����!";
}

node* Spisok::SearchRing(int el)
// ����� �������� el � ��������� ��������������� ������
//             � ��������� ��������� ������.
// nsp - ��������� �� ��������� ����� ������.
{
    node* q;//��������� �� ����� � ������� ������� ����� ����� �� ������
    node* p;//��������� �� ����� ������ �����
    node* Res;//��������� �� ��������� �����

    Res = NULL; //�� ��������� res ����� ���� ���� �� ���� ������ �����
    p = nsp;//p ����� ��������� ������� �� ���������
    if ((*((*p).sled)).elem == el)//���� ������ ������� ����� ������� ��������
        Res = (*p).sled;//����������� res ����� �� ����� ������ �������
    else
    {
        q = (*((*p).sled)).sled;//������� �� ������� �������� ������
        while (q != (*p).sled && Res == NULL)//���� �� �� ��������� ����� �� ������ ��������� ��������� � �� ����� ������� ������ �����
            if ((*q).elem == el)//���� ����� ����� ������ ��������
                Res = q;//����������� ����� ������� ����� ��������� res
            else  
                q = (*q).sled;//�������� � ���������� �����
    }
    return Res;//���������� ����� ���������� �����
}

void Spisok::InsAfter(node* Res, int el)
// ���������� � ��������� ��������������� ������ �����
// � �������������� ����� el �����  �����, ��  �������
// ��������� ������ Res.
{
    node* q;//���������� ������������ ��������

    q = new(node);//��������� ������ ��� ������������ ��������
    (*q).elem = el; //���������� ��������������� ���� ������������ ����� 
    (*q).sled = (*Res).sled;//����������� ��������� sled ������������ �������� �� ��������� ������� �� ������ res
    (*q).pred = (*(*Res).sled).pred;//����������� ��������� pred ������������ �������� �� ���������� �� ����������� ���������
    (*(*Res).sled).pred = q;//����������� ��������� pred, ���������� �� ����������� �����, �� ���� ����������� �����
    (*Res).sled = q;//����������� ��������� sled ����� res �� ����������� �����
}

void Spisok::InsBefore(node* Res, int el)
// ������� � ��������� ��������������� ������ �����
// � �������������� ����� el ����� ������, ��  �������
// ��������� ������ Res.
// nsp - ��������� �� ��������� ����� ������.
{
    node* q;//���������� ������������ ��������

    q = new(node);//��������� ������ ��� ������������ ��������
    (*q).elem = el;//���������� ��������������� ���� ������������ ����� 
    (*q).sled = (*(*Res).pred).sled;//����������� ��������� sled ������������ ����� �� ����� Res,�.� �� ��������� ����� ����� Res
    (*q).pred = (*Res).pred;//����������� ��������� pred ������������ �������� �� ���������� ����� �� ������ Res
    (*(*Res).pred).sled = q;//����������� ���������� sled ����� ����������� �� Res �� ����������� �������
    (*Res).pred = q;//����������� �������� pred ����� Res �� ����������� �������
    if (Res == (*nsp).sled) //���� ����� �������� ������� ����� ������ ��������� ������ �� ������� ��������� ���������
        (*nsp).sled = q;//����������� ��������� sled ������������� ����� �� ����������� �������
}

void Spisok::Delete(node* Res)
// �������� �� ���������� ���������������� ������
// �����, �� ������� ��������� ������ Res.
// nsp - ��������� �� ��������� ����� ������.
{
    if ((*Res).sled == Res)//���� ��������� sled ����� Res ��������� ��� �� ����, �� ���� �� ������� �� ������ �����
    {
        (*nsp).sled = NULL;//��������� �������� ��������� �� ����
        delete Res;//������� ����� �� ������
    }
    else
    {
        (*(*Res).sled).pred = (*Res).pred;//����������� ��������� pred ����� ���������� �� Res �� ���������� �� ������ Res
        (*(*Res).pred).sled = (*Res).sled;//����������� ��������� sled ����� ����������� �� Res �� ��������� �� ������ Res
        if ((*nsp).sled == Res)//���� ����� ������� ������ �����
            (*nsp).sled = (*Res).sled;//����������� ��������� sled ��������� �� ��������� ����� �� Res
        delete Res;//���������� ������ ���������� ��������
    }
}

void Spisok::DelAfter(node* Res)
// �������� �� ���������� ���������������� ������ �����,
// ��������������  �����  �����, ��  �������  ���������
// ������ Res.
// nsp - ��������� �� ��������� ����� ������.
{
    node* q;//��������� �� ��������� ����� ������� ����� ������� (������� ���� ����� ������ Res)

    if ((*Res).sled == Res)//���� ��������� sled ����� res ��������� ��� �� ����, �� �� ������� �� ������ �����
    {
        (*nsp).sled = NULL;//����������� ��������� sled ��������� �� ���� �.� �� ������ ������������ �����
        delete Res;//����������� ������ ���������� �����
    }
    else
    {
        q = (*Res).sled;//��������� ����� �� ��������� ����� �� Res
        (*(*(*Res).sled).sled).pred = (*(*Res).sled).pred;//����������� ��������� pred ���������� �� ��������� ������ �� ���������� �� ��������� ������
        (*Res).sled = (*(*Res).sled).sled;//����������� ��������� sled ����� Res �� ��������� �����  �� ��������� ������ 
        if ((*(*nsp).sled).pred == Res)//���� ������� ��������� �����
            // ������� "���������" ����� ������.
            (*nsp).sled = (*Res).sled;//���������� ��������� sled �� ��������� ����� �� Res 
        delete q;//����������� ������ ���������� �����
    }
}

void Spisok::Ochistka()
{
    node* q;//��������� �� ������� �����
    node* q1;//����������� �� ���� ����� ���������

    q = (*((*nsp).sled)).sled;//������������� ��������� �� ������ �����
    q1 = (*q).sled;//������������� ����������� ���������
    while (q1 != (*((*nsp).sled)).sled)//���� ����������� ��������� ����� ������� �����
    {
        delete q;//��������� ������ ���������� ��������
        q = q1;//������������� �������� ��������� �� ������������
        q1 = (*q1).sled;//������������� ���������� �������� �� ���������
    }
    delete q;//������� �������� ��������
    delete nsp;//������� ���������
}
