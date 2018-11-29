#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

 // Բ�̵�����
const int N = 20;
// ���ӱ�� 
const char POST[3] = {'A', 'B', 'C'};
// ��ʼλ�ú�Ŀ��λ�� 
const int from = 0, to = 1;

int main()
{
    int n=0, k, j;
    // �ƶ����̺� 
    int move; 
	// �洢���ϵ���
    stack<int> p[3];
	// ��ʼ�� 
    for(j=N-1; j>=0; j--){
        p[from].push(j);
    }
    
    
    while( p[to].size() != N ){
    	 // ��ʼ����
        n++;
        // �õ�Ҫ�ƶ��� 
    	for(move = 0; move < sizeof(int) * 8; move++ ){
    		if( (n >> move) & 1 ){
    			break;
			}
		}
		// �ƶ��� 
        for(k=0; k<3; k++){
        	// �ҵ��ƶ������ڵ��� 
            if( !p[k].empty() && p[k].top() == move) {
                for(j=k+1; j<k+3; j++){
                	int y = j % 3;
                	// �ҵ�Ŀ���� 
                    if( (p[y].empty() || p[y].top() >= move) ){
                        p[y].push( p[k].top() );
                        p[k].pop();
                        cout<< "Move " << move << " from " << POST[k] << " to " << POST[y] << endl;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    // ��֤�ƶ���� 
    cout<< "from: empty = " << p[from].empty() <<endl;
    
    cout<< "to: " << endl; 
    for(j=0; !p[to].empty(); j++){
        cout<< p[to].top() << endl;
        p[to].pop();
    }
    

    return 0;
}

