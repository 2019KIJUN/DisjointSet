#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Ʈ���� �̿��� ��ȣ ������ ������ �����Ѵ�.
struct OptimizedDisjointSet {
	vector<int> parent, rank;

	OptimizedDisjointSet(int n) : parent(n), rank(n, 1) { //�ʱ�ȭ
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	// u �� ���� Ʈ���� ��Ʈ�� ��ȣ�� ��ȯ�Ѵ�
	int find(int u) { //ã��
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	// u �� ���� Ʈ���� v �� ���� Ʈ���� ��ģ��
	void merge(int u, int v) { //��ġ��
		u = find(u); v = find(v);
		// �̹� ���� ���� Ʈ���� ���� ���
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		// ���� �׻� rank[v] �� �� ũ�Ƿ� u �� v �� �ڽ����� �ִ´�
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
	}
};
int main()
{
	OptimizedDisjointSet d(10); //0~9������ ��ȣ ��Ÿ�� ���� ����.
	d.merge(0, 1); //0�� 1�� ���� �����̴�.
	d.merge(1, 2); //1�� 2�� ���� �����̴�.
	d.merge(2, 3); //2�� 3�� ���� �����̴�. �ᱹ 0,1,2,3�� ��� ���� �����̴�.

	cout << "f = " << d.find(0) << endl; //0,1,2,3�� �θ� ����غ��� ��� ������ �θ� �����°� Ȯ���Ҽ� �ִ�.
	cout << "f = " << d.find(1) << endl;
	cout << "f = " << d.find(2) << endl;
	cout << "f = " << d.find(3) << endl;
	return 0;
}
