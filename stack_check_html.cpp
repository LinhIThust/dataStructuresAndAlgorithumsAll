//ứng dụng của stack trong việc kiểm tra tính đúng đắn của xâu ngoặc
//ví dụ ta có đề bài sau: Nhập vào một chuỗi bao gồm các xâu ngoặc, hãy kiểm tra tính đúng
//đắn của nó, xâu ngoặc đúng là xâu ngoặc có dấu mở ngoặc và dấu đóng ngoặc đúng lúc và phù hợp nhau
//vd xâu ngoặc đúng:
//Ta sẽ kiểm tra các sâu ngoặc sau?
//(){}
//[()]
//[()(){}]
//{}()
//vd xâu ngoặc sai:
//{{})//ví dụ
//{(})
//{}()(}
//([]})
//Ta sẽ ứng dụng  stack kiểm tra như sau:
//- Đầu tiên ta sẽ duyệt hết các chuỗi vừa nhập, nếu gặp dấu mở ngoặc thì push hết vào stack
//-Nếu gặp dấu đóng ngoặc ta sẽ lấy dấu mở ngoặc của dấu ngoặc đó trên đỉnh stack kiểm tra xem có
//hợp nhau hay không
//vd: [()];
//stack: [
//Gặp dấu mở đầu tiên push [
//Gặp dấu mở thứ hai push (
//-Gặp dấu đóng ) lấy đỉnh stack là dấu ( so sánh thấy chúng hợp nhau và xóa dấu đó khỏi đỉnh stack
//->lần lượt đến hết chuỗi
//Lưu ý : Các bạn có thể tạo một stack riêng hoặc có thể sử dụng stack trong thư viện chuẩn STL C++
//
//Ta sẽ code như sau:
#include<iostream>
#include<string>
#include<stack>
using namespace std;
//Ta sẽ tạo một hàm riêng để kiểm tra

bool KiemTraXauNgoac(string str,stack<char> a)
{
	//string str là chuỗi xâu ngoặc sẽ nhập vào
	for(int i=0;i<str.size();i++)//duyệt lần lượt hết chuỗi
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//nếu gặp dấu mở ngoặc
		{
			a.push(str[i]);//push hết vào stack
		}
		else //nếu gặp dấu đóng ngoặc
		{
			if(!a.empty())//nếu stack khác rỗng
			{
				if(str[i]==']')//kiểm tra xem phần tử ngoặc đỉnh stack có hợp với str[i] hay không
				{
					if(a.top()!='[')//không hợp
					{
						return false;//sai
					}
				}
				if(str[i]==')')//kiểm tra xem phần tử ngoặc đỉnh stack có hợp với str[i] hay không
				{
					if(a.top()!='(')//không hợp
					{
						return false;//sai
					}
				}
				if(str[i]=='}')//kiểm tra xem phần tử ngoặc đỉnh stack có hợp với str[i] hay không
				{
					if(a.top()!='{')//không hợp
					{
						return false;//sai
					}
				}
				a.pop();//kiểm tra xong xóa nó đi
			}
			else //nếu như stack rỗng, không hợp lệ, có dấu mở mà không có đóng
			{
				return false;
			}
		}
	}
	return a.empty()==true;
	//nếu như cuối cùng stack vẫn rỗng các phần tử đã lấy ra kiểm tra phù hợp hết
}
int main()
{
	//ví dụ có chuỗi str;
	string str;
	stack<char> a;
	getline(cin,str);
	if(KiemTraXauNgoac(str,a)==true)
	{
		cout<<"Xau ngoac dung"<<endl;
	}
	else
	{
		cout<<"xau ngoac sai:"<<endl;
	}
	//system("pause");
	//Chào các bạn !!!
	return 0;
}