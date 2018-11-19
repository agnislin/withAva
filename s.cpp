#include<iostream>
#include<stack>
using namespace std;


const int N = 5; // 圆盘的数量
const char POST[3] = {'A', 'B', 'C'}; // 盘符

int main()
{
    int n=0, move, k, j;

    stack<int> p[3];// 存储柱上的盘

    char t;
    cout<< "From A to ";
    cin>> t;

    for(j=N-1; j>=0; j--){
        p[0].push(j);
    }
    cout<< p[0].top() <<endl;
    while( p[ 1 ].size() != N ){
        n++; // 开始计数
    	for(move = 0; move < sizeof(int) * 8; move++ ){ // 遍历计算器的每一位
    		if( (n >> move) & 1 ){ // 从低位开始，查找值为1的位，它的值将对应盘符
    		
    			break;
			}
		}
		cout << "============" << endl;
        for(k=0; k<3; k++){
            if( !p[k].empty() ){// 找到移动盘符所在的柱
            
            		cout<< k << "   "  << p[k].top() << " == " << move << endl;
            	if ( p[k].top() == move) {
            		cout<< k << "   "  <<"     " <<p[k].top() << " == " << move << endl;
		                for(j=0; j<5; j++){
		                    if( k > j%3 && (p[j].empty() || p[j].top() >= move) ){ // 移动到其它的
		                        p[j].push( p[k].top() );
		                        p[k].pop();
		                        cout<< "move " << move << " from " << POST[k] << " to " << POST[j] << endl;
		                        break;
		                    }
		                }
		                
		                break;
				}
            }
        }
    }

    return 0;
}
