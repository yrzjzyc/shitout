#include<iterator>
#include<algorithm>
#include<vector>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Cell;
priority_queue<Cell> cellQueue;

private:
public:
	Cell(int birth) : id(count++) {	//birth为细胞诞生时间
		//初始化，确定细胞分裂时间
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN))
                      + SPLIT_TIME_MIN;
	}
	int getId() const { return id; }		//得到细胞编号
	int getSplitTime() const { return time; }	//得到细胞分裂时间
	bool operator < (const Cell& s) const      //定义“<”
    { return time > s.time; }
	void split() {	//细胞分裂
	    Cell child1(time), child2(time);	//建立两个子细胞
	    cout << time << "s: Cell #" << id << " splits to #"
		<< child1.getId() << " and #" << child2.getId() << endl;
	    cellQueue.push(child1);	//将第一个子细胞压入优先级队列
	    cellQueue.push(child2);	//将第二个子细胞压入优先级队列
	}
};
int Cell::count = 0;

int main() {
	int t;	//模拟时间长度
	cin >> t;
	cellQueue.push(Cell(0));	//将第一个细胞压入优先级队列
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.pop();	//将刚刚分裂的细胞弹出
	}
	return 0;
}
