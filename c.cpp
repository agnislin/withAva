#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

 // 圆盘的数量
const int N = 20;
// 柱子编号 
const char POST[3] = {'A', 'B', 'C'};
// 起始位置和目标位置 
const int from = 0, to = 1;

int main()
{
    int n=0, k, j;
    // 移动的盘号 
    int move; 
	// 存储柱上的盘
    stack<int> p[3];
	// 初始化 
    for(j=N-1; j>=0; j--){
        p[from].push(j);
    }
    
    
    while( p[to].size() != N ){
    	 // 开始计数
        n++;
        // 得到要移动盘 
    	for(move = 0; move < sizeof(int) * 8; move++ ){
    		if( (n >> move) & 1 ){
    			break;
			}
		}
		// 移动盘 
        for(k=0; k<3; k++){
        	// 找到移动盘所在的柱 
            if( !p[k].empty() && p[k].top() == move) {
                for(j=k+1; j<k+3; j++){
                	int y = j % 3;
                	// 找到目标柱 
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
    
    // 验证移动结果 
    cout<< "from: empty = " << p[from].empty() <<endl;
    
    cout<< "to: " << endl; 
    for(j=0; !p[to].empty(); j++){
        cout<< p[to].top() << endl;
        p[to].pop();
    }
    

    return 0;
}

