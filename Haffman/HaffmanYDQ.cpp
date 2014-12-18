//// Haffman.cpp : Defines the entry point for the console application.
////
//#include "BTNode.h"
//#include <stdio.h>
//#include <tchar.h>
//
//#include <fstream>
//#include <vector>
//#include <iostream>
//#include <iomanip>
//using namespace std;
//#define totalsize 52 
//
//int kinds_num = 0;//文件中有多少种字符
//int chars_num = 0;//文件中有多少字符
//
//
//int compare_num_DI = 0;
//int swap_num_DI = 0;
//int compare_num_SH = 0;
//int swap_num_SH = 0;
//int compare_num_B = 0;
//int swap_num_B = 0;
//int compare_num_Q = 0;
//int swap_num_Q = 0;
//int compare_num_SL = 0;
//int swap_num_SL = 0;
//int compare_num_HEAP = 0;
//int swap_num_HEAP = 0;
//int compare_num_Merge = 0;
//int swap_num_Merge = 0;
//
//
//int add0_num = 0;
//int sp_num_tohead = 0;
//int sp_num_truesize = 0;
//
//char* data_chars;//读入字符串
//BTNode *info_nodes;//储存字符串各编码
//BTNode *info_nodes_store;
//
///************************************************************************/
///* 读入并统计生成列表                                                   */
///************************************************************************/
//void showDataFromTxt()
//{
//	//读入字符串
//	chars_num = 0;
//	fstream data_in_txt;
//	data_in_txt.open("data.txt", ios::out || ios::in);
//	if (!data_in_txt)
//	{
//		cout << "error!" << endl;
//	}
//	else
//	{
//		char ch_for_num;//只为记数
//		while (!data_in_txt.eof()){
//			data_in_txt.get(ch_for_num);
//			chars_num++;
//		}
//		data_in_txt.close();
//		data_in_txt.open("data.txt", ios::out || ios::in);
//		data_chars = new char[chars_num];//多了一个
//
//		for (int j = 0; j < chars_num - 1; j++){
//			data_in_txt.get(data_chars[j]);
//			cout << data_chars[j];
//		}
//		cout << endl;
//	}
//}
//
//int getData_makeList(){
//	int kinds_num_t = 0;
//	info_nodes = new BTNode[totalsize * 2 - 1 + 1];
//	for (int i = 0; i<totalsize * 2 - 1; i++)
//	{
//		info_nodes[i].ch = '*';
//		info_nodes[i].lchild = NULL;
//		info_nodes[i].isable = false;
//		info_nodes[i].rchild = NULL;
//		info_nodes[i].num = 0;
//		info_nodes[i].percent = 0;
//
//		info_nodes[i].Father_int = 200;
//		info_nodes[i].left_int = 200;
//		info_nodes[i].right_int = 200;
//	}
//	for (int i = 0; i<totalsize; i++)
//	{
//		if (i<26)
//		{
//			info_nodes[i].ch = i + 65;
//			info_nodes[i].num = 0;
//			info_nodes[i].percent = 0;
//			info_nodes[i].str = "";
//		}
//		if (i >= 26 && i<52)
//		{
//			info_nodes[i].ch = i + 71;
//			info_nodes[i].num = 0;
//			info_nodes[i].percent = 0;
//			info_nodes[i].str = "";
//		}
//		if (i == 52)
//		{
//			info_nodes[i].ch = ',';
//			info_nodes[i].num = 0;
//			info_nodes[i].percent = 0;
//			info_nodes[i].str = "";
//		}
//		if (i == 53)
//		{
//			info_nodes[i].ch = '.';
//			info_nodes[i].num = 0;
//			info_nodes[i].percent = 0;
//			info_nodes[i].str = "";
//		}
//		if (i == 54)
//		{
//			info_nodes[i].ch = ':';
//			info_nodes[i].num = 0;
//			info_nodes[i].percent = 0;
//			info_nodes[i].str = "";
//		}
//	}
//	for (int i = 0; i < chars_num - 1; i++)
//	{
//		int chASCII = -1;
//		if (data_chars[i] <= 'Z'&&data_chars[i] >= 'A')
//		{
//			chASCII = data_chars[i] - 65;
//		}
//		if (data_chars[i] <= 'z'&&data_chars[i] >= 'a')
//		{
//			chASCII = data_chars[i] - 71;
//		}
//		if (data_chars[i] == ',')
//		{
//			chASCII = 52;
//		}
//		if (data_chars[i] == '.')
//		{
//			chASCII = 53;
//		}
//		if (data_chars[i] == ':')
//		{
//			chASCII = 54;
//		}
//		info_nodes[chASCII].num++;
//		info_nodes[chASCII].percent = info_nodes[chASCII].num / (chars_num - 1.0);
//	}
//
//	for (int i = 0; i<totalsize; i++)
//	{
//		if (info_nodes[i].num != 0)
//		{
//			kinds_num_t++;
//		}
//		// 		cout<<"char: "<<info[i].ch<<"  num: "<<info[i].num 
//		// 			   <<" percent: "<<info[i].percent*100<<"%"<<endl;
//
//	}
//	cout << "共有" << kinds_num_t << "种字符" << endl;
//	return kinds_num_t;
//}
///************************************************************************/
///* 关于排序的几个函数                                                   */
///************************************************************************/
//void form()
//{
//	cout << setw(10) << " " << setw(15) << "插入排序" << setw(15) << "shell排序" << setw(15) << "冒泡排序" << setw(15) << "快速排序" << endl;
//	cout << setw(10) << "比较次数:" << setw(15) << compare_num_DI << setw(15) << compare_num_SH << setw(15) << compare_num_B << setw(15) << compare_num_Q << endl;
//	cout << setw(10) << "交换次数:" << setw(15) << swap_num_DI << setw(15) << swap_num_SH << setw(15) << swap_num_B << setw(15) << swap_num_Q << endl;
//	cout << setw(10) << " " << setw(15) << "选择排序" << setw(15) << "堆排序" << setw(15) << "归并排序" << setw(15) << "快排优化" << endl;
//	cout << setw(10) << "比较次数:" << setw(15) << compare_num_SL << setw(15) << compare_num_HEAP << setw(15) << compare_num_Merge << setw(15) << "未完成" << endl;
//	cout << setw(10) << "交换次数:" << setw(15) << swap_num_SL << setw(15) << swap_num_HEAP << setw(15) << swap_num_Merge << setw(15) << "未完成" << endl;
//}
//void swap(BTNode &a, BTNode &b){
//
//	BTNode t = b;
//	b = a;
//	a = t;
//}
///************************************************************************/
///* 直接插入和shell排序                                                  */
///************************************************************************/
//void DISort(int begin, int incr, int &swap_num_SH, int &compare_num_SH){
//
//	for (int i = begin + incr; i < totalsize - 1; i += incr)
//	{
//		for (int j = i; compare_num_SH++, j >= begin + incr&&info_nodes[j].num>info_nodes[j - incr].num; j -= incr)//对for循环的理解！
//		{
//
//			swap(info_nodes[j], info_nodes[j - incr]);
//			swap_num_SH++;
//		}
//	}
//
//}
//void DISort(){
//
//	for (int i = 1; i < totalsize - 1; i++)
//	{
//		for (int j = i; compare_num_DI++, j >= 1 && info_nodes[j].num>info_nodes[j - 1].num; j--)//对for循环的理解！
//		{
//			swap(info_nodes[j], info_nodes[j - 1]);
//			swap_num_DI++;
//		}
//	}
//}
//void DISortGC(){
//
//	for (int i = 1; i < totalsize - 1; i++)
//	{
//
//		int k = i;//太丢人了。。。
//		for (int j = i - 1; j >= 0 && info_nodes[i].num>info_nodes[j].num; j--)
//		{
//			swap(info_nodes[i], info_nodes[j]);
//			i--;
//		}
//		i = k;
//	}
//	for (int i = 0; i<totalsize - 1; i++)
//	{
//		cout << "char: " << info_nodes[i].ch << "  num: " << info_nodes[i].num
//			<< " percent: " << info_nodes[i].percent * 100 << "%" << endl;
//	}
//}
//void ShellSort(){
//	int incr = totalsize - 1;
//	do{//煮一下这里
//		incr = incr / 3 + 1;
//		for (int i = 0; i <incr; i++)
//		{
//			DISort(i, incr, swap_num_SH, compare_num_SH);
//		}
//	} while (incr > 1);
//}
///************************************************************************/
///* 选择排序和堆排序                                                     */
///************************************************************************/
//void SelectSort()
//{
//	int t = 0;
//	for (int i = 0; i < totalsize; i++)
//	{
//		t = i;
//		for (int j = i + 1; j<totalsize; j++)
//		{
//			if (compare_num_SL++&&info_nodes[j].num>info_nodes[t].num)
//			{
//				t = j;
//			}
//		}
//		swap_num_SL++;
//		swap(info_nodes[t], info_nodes[i]);
//	}
//}
//
//int parent(int i)
//{
//	return (int)(i / 2);
//}
//
//int left(int i)
//{
//	return 2 * i;
//}
//
//int right(int i)
//{
//	return (2 * i + 1);
//}
//
//void Max_Heapify(int i, int heap_size)
//{
//	int l = left(i);
//	int r = right(i);
//	int largest;
//	if (l < heap_size && info_nodes[l].num < info_nodes[i].num&&compare_num_HEAP++)
//	{
//		largest = l;
//	}
//	else
//	{
//		largest = i;
//	}
//	if (r < heap_size &&info_nodes[r].num < info_nodes[largest].num&&compare_num_HEAP++)
//	{
//		largest = r;
//	}
//	if (largest != i)
//	{
//		swap(info_nodes[largest], info_nodes[i]);
//		swap_num_HEAP++;
//		Max_Heapify(largest, heap_size);
//	}
//}
//
//void Build_Max_Heap()
//{
//	for (int i = 52 / 2; i >= 0; i--)
//	{
//		Max_Heapify(i, 51);
//	}
//}
//
//
//void HeapSort(int heap_size)
//{
//	Build_Max_Heap();
//	for (int i = heap_size - 1; i > 0; i--)
//	{
//		swap(info_nodes[0], info_nodes[i]);
//		swap_num_HEAP++;
//		Max_Heapify(0, i);
//	}
//}
///************************************************************************/
///* 冒泡排序和快速排序                                                   */
///************************************************************************/
//void BubbleSort()
//{
//	int i = 0;
//	int j = 0;
//	bool flag = true;
//	for (i = 1; i<totalsize - 1 && flag; i++)
//	{
//		flag = false;
//		for (j = totalsize - 1; j >= i; j--)
//		{
//			compare_num_B++;
//			if (info_nodes[j].num>info_nodes[j - 1].num)
//			{
//				swap(info_nodes[j], info_nodes[j - 1]);
//				swap_num_B++;
//				flag = true;
//			}
//		}
//	}
//}
//int Partition(int low, int high){
//	BTNode p = info_nodes[low];
//	int c = high;
//	while (low<high){
//		if (c == high)
//		{
//			if (compare_num_Q++&&info_nodes[high].num>p.num)
//			{
//				swap_num_Q++;
//				info_nodes[low] = info_nodes[high];
//				low++;
//
//				c = low;
//			}
//			else
//			{
//				high--;
//				c = high;
//			}
//		}
//		else
//		{
//			if (compare_num_Q++&&info_nodes[low].num<p.num)
//			{
//				swap_num_Q++;
//				info_nodes[high] = info_nodes[low];
//				high--;
//				c = high;
//			}
//			else
//			{
//				low++;
//				c = low;
//			}
//		}
//	}
//	info_nodes[low] = p;
//	return low;
//}
//void QSort(int s, int t){
//	if (s<t)
//	{
//		int pivotloc = Partition(s, t);
//		QSort(s, pivotloc - 1);
//		QSort(pivotloc + 1, t);
//	}
//}
//void QSortModify()
//{
//	QSort(0, kinds_num - 1);
//	cout << "方案1，2，3" << endl;
//}
///************************************************************************/
///* 归并排序                                                             */
///************************************************************************/
//
//void Merge(BTNode *SR, BTNode *TR, int i, int m, int n){
//	// 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
//	int j = m + 1;
//	int k = i;
//	for (; i <= m && j <= n; ++k){// 将SR中记录按关键字从小到大地复制到TR中
//		if (compare_num_Merge++&&SR[i].num >= SR[j].num){
//			TR[k] = SR[i++];
//			swap_num_Merge++;
//		}
//		else{
//			TR[k] = SR[j++];
//			swap_num_Merge++;
//		}
//	}
//	while (i <= m) TR[k++] = SR[i++];   // 将剩余的 SR[i..m] 复制到TR
//	while (j <= n) TR[k++] = SR[j++];   // 将剩余的 SR[j..n] 复制到TR
//}//Merge
//
//void Msort(BTNode *SR, BTNode *TR1, int s, int t){
//	// 对SR[s..t]进行归并排序，排序后的记录存入TR1[s..t]
//	if (s == t){
//		TR1[s] = SR[s];
//	}
//	else {
//		BTNode TR2[totalsize];
//		int m = (s + t) / 2;   // 将 SR[s..t] 平分为 SR[s..m] 和 SR[m+1..t]
//		Msort(SR, TR2, s, m);  // 递归地将 SR[s..m] 归并为有序的 TR2[s..m]
//		Msort(SR, TR2, m + 1, t); // 递归地将SR[m+1..t]归并为有序的TR2[m+1..t]
//		Merge(TR2, TR1, s, m, t); // 将TR2[s..m]和TR2[m+1..t] 归并到 TR1[s..t]
//	}// else
//} // Msort
//
//void MergeSort()
//{
//	Msort(info_nodes, info_nodes, 0, totalsize - 1);
//}
//
//void sort(){
//	cout << "请选择排序方式:" << endl << "1: 插入排序 2: shell排序 3：冒泡排序 4：快速排序 \n5: 选择排序 6: 堆排序\t 7: 归并排序 8: 快排优化" << endl;
//
//	int choice = 0;
//	cin >> choice;
//	switch (choice){
//	case 1:
//		compare_num_DI = 0;
//		swap_num_DI = 0;
//		kinds_num = getData_makeList();
//		DISort();
//		break;
//	case 2:
//		swap_num_SH = 0;
//		compare_num_SH = 0;
//		kinds_num = getData_makeList();
//		ShellSort();
//		break;
//	case 3:
//		swap_num_B = 0;
//		compare_num_B = 0;
//		kinds_num = getData_makeList();
//		BubbleSort();
//		break;
//	case 4:
//		swap_num_Q = 0;
//		compare_num_Q = 0;
//		kinds_num = getData_makeList();
//		QSort(0, totalsize - 1);//??????????????
//		break;
//	case 5:
//		swap_num_SL = 0;
//		compare_num_SL = 0;
//		kinds_num = getData_makeList();
//		SelectSort();
//		break;
//	case 6:
//		swap_num_HEAP = 0;
//		compare_num_HEAP = 0;
//		kinds_num = getData_makeList();
//		HeapSort(totalsize);
//		break;
//	case 7:
//		swap_num_Merge = 0;
//		compare_num_Merge = 0;
//		kinds_num = getData_makeList();
//		MergeSort();
//		break;
//	case 8:
//		swap_num_Q = 0;
//		compare_num_Q = 0;
//		kinds_num = getData_makeList();
//		QSortModify();
//		break;
//	default:
//		break;
//	}
//
//	cout << endl;
//	cout << "有效字符为:" << endl;
//	for (int i = 0; i<kinds_num; i++){
//		info_nodes[i].isable = true;
//		cout << setw(5) << "char:" << setw(3) << info_nodes[i].ch << setw(5) << "  num: " << setw(3) << info_nodes[i].num
//			<< setw(5) << " percent: " << setw(6) << info_nodes[i].percent * 100 << "%" << endl;
//	}
//	form();
//	//code();
//}
///************************************************************************/
///* 前序遍历生成编码                                                     */
///************************************************************************/
//void PreOrderTravel(BTNode* T){
//
//	if (T == NULL)
//	{
//		return;
//	}
//
//	BTNode *Tp = T->Father;//为了插入零和一
//	if (T->isleft(Tp) == 1)
//	{
//		T->str = Tp->str + '0';
//	}
//
//	if (T->isright(Tp) == 1)
//	{
//		T->str = Tp->str + '1';
//	}
//	PreOrderTravel(T->lchild);
//	PreOrderTravel(T->rchild);
//}
//void getNodes_code(){
//	int count1 = 0;
//
//	int count2 = 0;
//	int min1 = 0, min2 = 0;
//
//	while (count2 != kinds_num - 1){
//		min1 = totalsize * 2 - 1;
//		info_nodes[min1].num = 1000000;
//		for (int j = 0; j<kinds_num + count1; j++)
//		{
//			if (info_nodes[j].isable == true && info_nodes[j].num<info_nodes[min1].num)
//			{
//				min1 = j;
//			}
//		}
//		info_nodes[min1].isable = false;
//
//		min2 = totalsize * 2 - 1;
//		info_nodes[min2].num = 100000;
//		for (int j = 0; j<kinds_num + count1; j++)
//		{
//			if (info_nodes[j].isable == true && info_nodes[j].num<info_nodes[min2].num)
//			{
//				min2 = j;
//			}
//		}
//
//		info_nodes[min2].isable = false;
//
//		info_nodes[kinds_num + count1].num = info_nodes[min1].num + info_nodes[min2].num;
//		info_nodes[kinds_num + count1].rchild = &info_nodes[min1];
//		info_nodes[kinds_num + count1].right_int = min1;
//		info_nodes[kinds_num + count1].lchild = &info_nodes[min2];
//		info_nodes[kinds_num + count1].left_int = min2;
//		info_nodes[min1].Father = &info_nodes[kinds_num + count1];
//		info_nodes[min2].Father = &info_nodes[kinds_num + count1];
//		info_nodes[min1].Father_int = kinds_num + count1;
//		info_nodes[min2].Father_int = kinds_num + count1;
//		info_nodes[kinds_num + count1].isable = true;
//		count1++;
//		count2++;
//
//	}
//	sp_num_tohead = count1;
//
//	if (kinds_num != 1)
//	{
//		BTNode *node = &info_nodes[kinds_num - 1 + count1];
//		node->Father = NULL;
//		PreOrderTravel(node);
//	}
//	else
//	{
//		info_nodes[0].str = "0";
//	}
//	//ofstream data_code_txt;//这里要注意啊
//	//data_code_txt.open("code.txt",ios::out);
//	//if (!data_code_txt)
//	//{
//	//	cout<<"error!"<<endl;
//	//} 
//	//data_code_txt<<sp_num_truesize<<endl;
//	//data_code_txt<<kinds_num<<endl;
//	//data_code_txt<<sp_num_tohead<<endl;
//	//info_nodes_store = new BTNode[totalsize*2-1];
//	//for(int count1 = 0;count1<totalsize*2-1;count1++){
//	//	cout<<setw(5)<<"char:"<<setw(3)<<info_nodes[count1].ch<<setw(5)<<"num:"<<setw(3)<<info_nodes[count1].num 
//	//		<<setw(10)<<"percent:"<<setw(10)<<info_nodes[count1].percent*100<<"%"<<setw(10)<<"codes:"<<setw(10)<<info_nodes[count1].str<<endl;
//	//    //data_code_txt.put(info_nodes[count1].ch);
//	//	data_code_txt<<info_nodes[count1].ch<<endl;
//	//		data_code_txt<<info_nodes[count1].str<<endl;
//	//	data_code_txt<<info_nodes[count1].Father_int<<endl;
//	//	data_code_txt<<info_nodes[count1].left_int<<endl;
//	//	data_code_txt<<info_nodes[count1].right_int<<endl;
//	//	//data_code_txt.put(a);
//	//}
//	//data_code_txt.close();
//	//display();	
//
//	for (int count1 = 0; count1<totalsize * 2 - 1; count1++){
//		cout << setw(5) << "char:" << setw(3) << info_nodes[count1].ch << setw(5) << "num:" << setw(3) << info_nodes[count1].num
//			<< setw(10) << "percent:" << setw(10) << info_nodes[count1].percent * 100 << "%" << setw(10) << "codes:" << setw(10) << info_nodes[count1].str << endl;
//		//data_code_txt.put(info_nodes[count1].ch);
//		//data_code_txt.put(a);
//	}
//}
//void display(){
//	for (int i = 0; i<kinds_num - 1; i++){
//		cout << setw(5) << "char:" << setw(3) << info_nodes[i].ch << setw(5) << "num:" << setw(5) << info_nodes[i].num
//			<< setw(5) << "str" << setw(5) << info_nodes[i].str << endl;
//	}
//}
///************************************************************************/
///* 得到每个字符的编码                                                   */
///************************************************************************/
//string getCodes_of_theChar(char ch){
//	string str;
//	for (int i = 0; i<kinds_num; i++){
//		if (ch == info_nodes[i].ch)
//		{
//			str = info_nodes[i].str;
//		}
//	}
//	return str;
//}
//string getWholeDataCodes(){
//	string str;
//	for (int j = 0; j < chars_num - 1; j++){
//		str = str + getCodes_of_theChar(data_chars[j]);
//	}
//	cout << "unmodified:" << endl << str << endl << endl;
//	return str;
//}
//int charToint(char ch){
//	if (ch == '0')
//	{
//		return 0;
//	}
//	if (ch == '1')
//	{
//		return 1;
//	}
//}
//char getTheCharToSave(string str){
//	const char *chtosave = str.c_str();
//	int i = 0;
//	int k = 64;
//	for (int j = 0; j<7; j++)
//	{
//
//		i = i + charToint((char)chtosave[j])*k;
//		k = k / 2;
//	}
//	cout << str << endl;
//	cout << (char)i << endl;
//	return (char)i;
//}
//void save(string str){
//	ofstream save("save.txt");
//
//	if (!save)
//	{
//		cout << "error!" << endl;
//	}
//	sp_num_truesize = str.length();
//	add0_num = 7 - sp_num_truesize % 7;
//	for (int i = 0; i<add0_num; i++)
//	{
//		str = str + '0';
//	}
//	cout << "modified:" << endl << str << endl << endl;
//	const char *chtosave = str.c_str();
//	string chsave = "";
//	int j = 0;
//	int num = 0;
//	while (j <= sp_num_truesize + add0_num){
//		chsave = chsave + chtosave[j];
//		if (j != 0 && (j + 1) % 7 == 0)
//		{
//			save.put(getTheCharToSave(chsave));
//			chsave = "";
//			num++;
//		}
//		j++;
//	}
//	save.close();
//}
///************************************************************************/
///* 把字符转换为0和1                                                     */
///************************************************************************/
//string charToStr(char ch){
//	string str = "";
//	int i = (int)ch;
//	int k = 64;
//	for (int j = 0; j < 7; j++)
//	{
//		if (i >= k)
//		{
//			str = str + '1';
//			i = i - k;
//			k = k / 2;
//		}
//		else{
//			str = str + '0';
//			k = k / 2;
//		}
//	}
//	return str;
//}
//void decode(){
//
//	string str = "";
//	int totalchar1 = 0;
//	//读入字符串
//	fstream data;
//	data.open("save.txt", ios::out || ios::in);
//	if (!data)
//	{
//		cout << "error!" << endl;
//	}
//	else
//	{
//		char ch1;//只为记数
//		while (!data.eof()){
//			data.get(ch1);
//			totalchar1++;
//		}
//		data.close();
//		data.open("save.txt", ios::out || ios::in);
//		data_chars = new char[totalchar1];//多了一个
//		BTNode* T = &info_nodes[kinds_num - 1 + sp_num_tohead];
//
//		for (int j = 0; j < totalchar1; j++){//?????????????????????????
//			data.get(data_chars[j]);
//			//str = str + data_chars[j];
//			str = str + charToStr(data_chars[j]);
//		}
//
//		cout << str << endl;
//		const char* chars = str.c_str();
//		for (int i = 0; i <= sp_num_truesize; i++)
//		{
//			if (kinds_num == 1)
//			{
//				cout << T->ch;
//				T = &info_nodes[kinds_num - 1 + sp_num_tohead];
//
//			}
//			else if (T->lchild == NULL&&T->rchild == NULL){
//				cout << T->ch;
//				T = &info_nodes[kinds_num - 1 + sp_num_tohead];
//				i--;
//			}
//			else{
//				if (chars[i] == '0')
//				{
//					T = T->lchild;
//				}
//				if (chars[i] == '1')
//				{
//					T = T->rchild;
//				}
//			}
//		}
//	}
//	cout << endl;
//}
//void saveCode()
//{
//	ofstream data_code_txt;//这里要注意啊
//	data_code_txt.open("code.txt", ios::out);
//	if (!data_code_txt)
//	{
//		cout << "error!" << endl;
//	}
//	data_code_txt << sp_num_truesize << endl;
//	data_code_txt << kinds_num << endl;
//	data_code_txt << sp_num_tohead << endl;
//	info_nodes_store = new BTNode[totalsize * 2 - 1];
//	for (int count1 = 0; count1<totalsize * 2 - 1; count1++){
//		//data_code_txt.put(info_nodes[count1].ch);
//		data_code_txt << info_nodes[count1].ch << endl;
//		data_code_txt << info_nodes[count1].str << endl;
//		data_code_txt << info_nodes[count1].Father_int << endl;
//		data_code_txt << info_nodes[count1].left_int << endl;
//		data_code_txt << info_nodes[count1].right_int << endl;
//		//data_code_txt.put(a);
//	}
//	data_code_txt.close();
//}
//void decodeFromFile()
//{
//	fstream code;
//	code.open("code.txt", ios::in || ios::out);
//	if (!code)
//	{
//		cout << "error!" << endl;
//	}
//	string str;
//	int i = 0;
//	int j = 0;
//	char const *k;
//	info_nodes = new BTNode[totalsize * 2 - 1];
//	for (int i = 0; i<totalsize * 2 - 1; i++)
//	{
//		info_nodes[i].ch = '*';
//		info_nodes[i].lchild = NULL;
//		info_nodes[i].isable = false;
//		info_nodes[i].rchild = NULL;
//		info_nodes[i].num = 0;
//		info_nodes[i].percent = 0;
//
//		info_nodes[i].Father_int = 200;
//		info_nodes[i].left_int = 200;
//		info_nodes[i].right_int = 200;
//	}
//	getline(code, str);
//	k = str.c_str();
//	sp_num_truesize = ((int)(k[0]) - 48) * 100 + ((int)(k[1]) - 48) * 10 + ((int)(k[2]) - 48);
//	getline(code, str);
//	k = str.c_str();
//	kinds_num = ((int)(k[0]) - 48) * 10 + (int)(k[1]) - 48;
//	getline(code, str);
//	k = str.c_str();
//	sp_num_tohead = ((int)(k[0]) - 48) * 10 + (int)(k[1]) - 48;
//
//	while (getline(code, str))
//	{
//
//		if (i == 0)
//		{
//			k = str.c_str();
//			info_nodes[j].ch = k[0];
//		}
//		if (i == 1)
//		{
//			info_nodes[j].str = str;
//		}
//
//		if (i == 2)
//		{
//			k = str.c_str();
//
//			if (str.size() == 3)
//			{
//				info_nodes[j].Father_int = ((int)k[0] - 48) * 100 + ((int)k[1] - 48) * 10 + ((int)k[2] - 48);
//			}
//			if (str.size() == 2)
//			{
//				info_nodes[j].Father_int = ((int)k[0] - 48) * 10 + ((int)k[1] - 48);
//			}
//			if (str.size() == 1)
//			{
//				info_nodes[j].Father_int = ((int)k[0] - 48);
//			}
//
//			if (info_nodes[j].Father_int != 200)
//			{
//				info_nodes[j].Father = &info_nodes[info_nodes[j].Father_int];
//			}
//			else
//			{
//				info_nodes[j].Father = NULL;
//			}
//		}
//
//		if (i == 3)
//		{
//			k = str.c_str();
//
//			if (str.size() == 3)
//			{
//				info_nodes[j].left_int = ((int)k[0] - 48) * 100 + ((int)k[1] - 48) * 10 + ((int)k[2] - 48);
//			}
//			if (str.size() == 2)
//			{
//				info_nodes[j].left_int = ((int)k[0] - 48) * 10 + ((int)k[1] - 48);
//			}
//			if (str.size() == 1)
//			{
//				info_nodes[j].left_int = ((int)k[0] - 48);
//			}
//
//			if (info_nodes[j].left_int != 200)
//			{
//				info_nodes[j].lchild = &info_nodes[info_nodes[j].left_int];
//			}
//			else
//			{
//				info_nodes[j].lchild = NULL;
//			}
//		}
//
//		if (i == 4)
//		{
//			k = str.c_str();
//
//			if (str.size() == 3)
//			{
//				info_nodes[j].right_int = ((int)k[0] - 48) * 100 + ((int)k[1] - 48) * 10 + ((int)k[2] - 48);
//			}
//			if (str.size() == 2)
//			{
//				info_nodes[j].right_int = ((int)k[0] - 48) * 10 + ((int)k[1] - 48);
//			}
//			if (str.size() == 1)
//			{
//				info_nodes[j].right_int = ((int)k[0] - 48);
//			}
//
//			if (info_nodes[j].right_int != 200)
//			{
//				info_nodes[j].rchild = &info_nodes[info_nodes[j].right_int];
//			}
//			else
//			{
//				info_nodes[j].rchild = NULL;
//			}
//		}
//		i++;
//		if (i == 5)
//		{
//			i = 0;
//			j++;
//		}
//
//	}
//}
//
//void printMainScreen()
//{
//	cout << endl << "please input your choice:" << endl << "1:show the text\n2:show the list\n3:show the codes\n4:compress and save\n5:decode\n6:decode from file" << endl << "#";
//}
//int _tmain0(int argc, _TCHAR* argv[])
//{
//	printMainScreen();
//	int i;
//	cin >> i; cout << endl;
//	while (i != 8)
//	{
//		switch (i)
//		{
//		case 1:
//			showDataFromTxt();
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		case 2:
//			showDataFromTxt();
//			sort();
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		case 3:
//			getNodes_code();;
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		case 4:
//			save(getWholeDataCodes());
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		case 5:
//			decode();
//			saveCode();
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		case 6:
//			decodeFromFile();
//			decode();
//			printMainScreen();
//			cin >> i; cout << endl;
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}
//
//
