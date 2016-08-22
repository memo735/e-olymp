#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX 1000000000

priority_queue<int, vector<int>, greater<int> > mMinHeap;
priority_queue<int, vector<int>, less<int> > mMaxHeap;
int c, n;

//Инициализируем кучи. В переменной c подсчитываем количество поступивших на вход чисел.
int main() {
	mMaxHeap.push(-MAX); mMinHeap.push(MAX);
	c = 1;

	//Обрабатываем очередное число.
	while (scanf("%d", &n) == 1)
	{
		//В зависимости от значения n заносим его в одну из куч.
		if (n >= mMinHeap.top()) mMinHeap.push(n);
		else mMaxHeap.push(n);

		//Если размер max - кучи больше размера min - кучи или размер min - кучи более
		//чем на один элемент превышает размер max - кучи, то проводим их балансировку.
		if (mMaxHeap.size() > mMinHeap.size())
		{
			//Наибольший элемент max - кучи переносим в min - кучу.
			int temp = mMaxHeap.top();
			mMaxHeap.pop();
			mMinHeap.push(temp);
		}
		else
			if (mMaxHeap.size() + 1 < mMinHeap.size())
			{
				//Наименьший элемент min - кучи переносим в max - кучу.
				int temp = mMinHeap.top();
				mMinHeap.pop();
				mMaxHeap.push(temp);
			}

		//В зависимости от четности количества элементов в массиве выводим значение медианы.
		if (c % 2) printf("%d\n", mMinHeap.top());
		else printf("%d\n", (mMinHeap.top() + mMaxHeap.top()) / 2);
		c++;
	}
	return 0;
}
