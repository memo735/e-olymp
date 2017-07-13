#include "stdafx.h"
#include <iostream>
#include <map>
#include <assert.h>
#include <string>

using namespace std;

void process(const string &compound, map<string, int> &count, int mult = 1)
{
	if (compound.length() == 0) return;

	string::size_type atom_len = 0, count_len = 0;
	int atom_count = 1;
	if (isupper(compound[0])) {
		// handle atom at the beginning
		atom_len++;
		if (compound.length() > 1 && islower(compound[1])) {
			atom_len++;
			if (compound.length() > 2 && islower(compound[2])) atom_len++;
		}
		if (compound.length() > atom_len && isdigit(compound[atom_len])) {
			count_len = 1;
			atom_count = compound[atom_len] - '0';
		}
		count[compound.substr(0, atom_len)] += atom_count * mult;
		process(compound.substr(atom_len + count_len), count, mult);
	}
	else if (compound[0] == '(') {
		// handle bracket
		int level = 1;
		string::size_type i;
		for (i = 1; i < compound.length(); i++) {
			if (compound[i] == '(') level++;
			else if (compound[i] == ')') level--;
			if (level == 0) break;
		}
		assert(i < compound.length());
		atom_len = i + 1;                   // treat unit as atom
		if (atom_len < compound.length() && isdigit(compound[atom_len])) {
			count_len = 1;
			atom_count = compound[atom_len] - '0';
		}
		process(compound.substr(1, atom_len - 2), count, atom_count*mult);
		process(compound.substr(atom_len + count_len), count, mult);
	}
	else assert(false);
}

void process(const string &compound)
{
	map<string, int> count;
	process(compound, count);
	for (map<string, int>::const_iterator it = count.begin();
		it != count.end(); ++it) {
		if (it != count.begin()) cout << "+";
		if (it->second > 1) cout << it->second;
		cout << it->first;
	}
	cout << endl;
}

int main()
{
	string compound;
	while (getline(cin, compound)) process(compound);
	return 0;
}
