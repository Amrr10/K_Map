#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include<iomanip>

using namespace std;

void var2(vector <int> v)
{
int kmap2[2][2] = { 0 };
for (int i = 0; i < v.size(); i++)
{
if (v[i] == 0)
kmap2[0][0] = 1;
if (v[i] == 1)
kmap2[0][1] = 1;
if (v[i] == 2)
kmap2[1][0] = 1;
if (v[i] == 3)
kmap2[1][1] = 1;
}

int i = 0;
for (int j = 0; j < 2; j++)
{
cout << kmap2[i][j] << " ";
}
cout << endl;
i = 1;
for (int j = 0; j < 2; j++)
{
cout << kmap2[i][j] << " ";
}
cout << endl;

	string result[14];

	for (int i = 0; i < 14; i++) {
		result[i] = "0";
	}

	bool opt[2][2];
	bool fullyopt = false;
	int min = 1;
	int count = 0;	

	for (int o = 0; o < 2; o++) { 
		for (int i = 0; i < 2; i++) {
			if (kmap2[o][i] == 0) opt[o][i] = true;
			else opt[o][i] = false;
		}
	}

	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < 2; j++) {
			if (kmap2[k][j] < min) min = kmap2[k][j];
		}
	}

	if (min == 1) {	
		fullyopt = true;
		cout << "F = 1\n";
	}
	
    else{
	if (!fullyopt) {		
		min = 1;

		for (int i = 0; i < 2; i++) {		
			if (kmap2[0][i] < min) min = kmap2[0][i];
		}

		if (min == 1) {	
			for (int i = 0; i < 2; i++) opt[0][i] = true;
			result[count] = "A'";
			count++;
		}
		else {		
			min = 1;

			for (int i = 0; i < 2; i++) {		
				if (kmap2[1][i] < min) min = kmap2[1][i];
			}

			if (min == 1) {	
				for (int i = 0; i < 2; i++) opt[1][i] = true;
				result[count] = "A";
				count++;
			}
		}

		fullyopt = true;	

		for (int c = 0; c < 2; c++) {		
			for (int j = 0; j < 2; j++) {
				if (opt[c][j] == false) {
					fullyopt = false;
					break;
				}
			}
			if (!fullyopt) break;
		}

			fullyopt = true;

			for (int c = 0; c < 2; c++) {		
				for (int j = 0; j < 2; j++) {
					if (opt[c][j] == false) {
						fullyopt = false;
						break;
					}
				}
				if (!fullyopt) break;
			}

			if (!fullyopt) {		
				if ((kmap2[0][0] == 1) && (kmap2[0][1])) {		//1
					if ((opt[0][0] == false) || (opt[0][1] == false)) {
						opt[0][0] = true; opt[0][1] = true;
						result[count] = "A'";
						count++;
					}
				}

				if ((kmap2[1][0] == 1) && (kmap2[1][1])) {		//2
					if ((opt[1][0] == false) || (opt[1][1] == false)) {
						opt[1][0] = true; opt[1][1] = true;
						result[count] = "A";
						count++;
					}
				}
			
			
				if ((kmap2[0][0] == 1) && (kmap2[1][0])) {		//3
					if ((opt[0][0] == false) || (opt[1][0] == false)) {
						opt[0][0] = true; opt[1][0] = true;
						result[count] = "B'";
						count++;
					}
				}

				if ((kmap2[1][1] == 1) && (kmap2[0][1])) {		//4
					if ((opt[1][1] == false) || (opt[0][1] == false)) {
						opt[1][1] = true; opt[0][1] = true;
						result[count] = "B";
						count++;
					}
				}
			
				if ((kmap2[0][0] == 1) && (kmap2[1][1])) {		//5
					if ((opt[0][0] == false) || (opt[1][1] == false)) {
						opt[0][0] = true; opt[1][1] = true;
						result[count] = "A'B'+ AB";
						count++;
					}
				}
			
				if ((kmap2[1][0] == 1) && (kmap2[0][1])) {		//6
					if ((opt[1][0] == false) || (opt[0][1] == false)) {
						opt[1][0] = true; opt[0][1] = true;
						result[count] = "AB' + A'B";
						count++;
					}
				}
				
				if ((kmap2[0][0] == 1) && (kmap2[0][1])&& (kmap2[1][0])) {		//7
					if ((opt[0][0] == false) || (opt[0][1] == false)|| (opt[1][0] == false)) {
						opt[0][0] = true; opt[0][1] = true; opt[1][0] = true;
						result[count] = "A' + B'";
						count++;
					}
				}
			
				if ((kmap2[0][0] == 1) && (kmap2[0][1])&& (kmap2[1][1])) {		//8
					if ((opt[0][0] == false) || (opt[0][1] == false)|| (opt[1][1] == false)) {
						opt[0][0] = true; opt[0][1] = true; opt[1][1] = true;
						result[count] = "A + B'";
						count++;
					}
				}
				
				if ((kmap2[0][1] == 1) && (kmap2[1][1])&& (kmap2[1][0])) {		//9
					if ((opt[0][1] == false) || (opt[1][1] == false)|| (opt[1][0] == false)) {
						opt[0][1] = true; opt[1][1] = true; opt[1][0] = true;
						result[count] = "A + B";
						count++;
					}
				}
				
				if ((kmap2[0][0] == 1) && (kmap2[0][1])&& (kmap2[1][1])) {		//10
					if ((opt[0][0] == false) || (opt[0][1] == false)|| (opt[1][1] == false)) {
						opt[0][0] = true; opt[0][1] = true; opt[1][1] = true;
						result[count] = "A' + B";
						count++;
					}
				}
			
				fullyopt = true;

				for (int c = 0; c < 2; c++) {		
					for (int j = 0; j < 4; j++) {
						if (opt[c][j] == false) {
							fullyopt = false;
							break;
						}
					}
					if (!fullyopt) break;
				}

				if (!fullyopt) { 
					if (opt[0][0] == false) {		//1
						opt[0][0] = true;
						result[count] = "A'B'";
						count++;
					}

					if (opt[0][1] == false) {		//2
						opt[0][1] = true;
						result[count] = "A'B";
						count++;
					}

					if (opt[1][0] == false) {		//3
						opt[1][0] = true;
						result[count] = "AB'";
						count++;
					}

					if (opt[1][1] == false) {		//4
						opt[1][1] = true;
						result[count] = "AB";
						count++;
					}
					
					fullyopt = true;

					for (int c = 0; c < 2; c++) {		
						for (int j = 0; j < 4; j++) {
							if (opt[c][j] == false) {
								fullyopt = false;
								break;
							}
						}
						if (!fullyopt) break;
					}
				}
			}
		}
		
cout <<"F = ";
	int counter = 0;
	while (result[counter + 1] != "0") {
		cout<< setw(3) << result[counter] << setw(3) << "+ " << setw(3);
		counter++;
	}
	cout << result[counter] << "\n";

}}

void var3(vector <int> v3)
{
int kmap3[2][4] = { 0 };
for (int i = 0; i < v3.size(); i++)
{
if (v3[i] == 0)
kmap3[0][0] = 1;
if (v3[i] == 1)
kmap3[0][1] = 1;
if (v3[i] == 2)
kmap3[0][3] = 1;
if (v3[i] == 3)
kmap3[0][2] = 1;
if (v3[i] == 4)
kmap3[1][0] = 1;
if (v3[i] == 5)
kmap3[1][1] = 1;
if (v3[i] == 6)
kmap3[1][3] = 1;
if (v3[i] == 7)
kmap3[1][2] = 1;
}
int i = 0;
for (int j = 0; j < 4; j++)
{
cout << kmap3[i][j] << " ";
}
cout << endl;
i = 1;
for (int j = 0; j < 4; j++)
{
cout << kmap3[i][j] << " ";
}
cout << endl;


	string result[25];

	for (int i = 0; i < 25; i++) {
		result[i] = "0";
	}

	bool opt[2][4];
	bool fullyopt = false;
	int min = 1;
	int count = 0;	
	for (int o = 0; o < 2; o++) { 
		for (int i = 0; i < 4; i++) {
			if (kmap3[o][i] == 0) opt[o][i] = true;
			else opt[o][i] = false;
		}
	}

	for (int k = 0; k < 2; k++) {
		for (int j = 0; j < 4; j++) {
			if (kmap3[k][j] < min) min = kmap3[k][j];
		}
	}

	if (min == 1) {		
		fullyopt = true;
		cout << "F = 1\n";
	}
	
    else
    {
	if (!fullyopt) {	
		min = 1;

		for (int i = 0; i < 4; i++) {		
			if (kmap3[0][i] < min) min = kmap3[0][i];
		}

		if (min == 1) {		
			for (int i = 0; i < 4; i++) opt[0][i] = true;
			result[count] = "A'";
			count++;
		}
		else {		
			min = 1;

			for (int i = 0; i < 4; i++) {	
				if (kmap3[1][i] < min) min = kmap3[1][i];
			}

			if (min == 1) {	
				for (int i = 0; i < 4; i++) opt[1][i] = true;
				result[count] = "C";
				count++;
			}
		}

		fullyopt = true;	

		for (int c = 0; c < 2; c++) {		
			for (int j = 0; j < 4; j++) {
				if (opt[c][j] == false) {
					fullyopt = false;
					break;
				}
			}
			if (!fullyopt) break;
		}

		if (!fullyopt) {		
			if (kmap3[0][0] == 1) {	
				if ((kmap3[0][1] == 1) && (kmap3[1][0] == 1) && (kmap3[1][1] == 1)) {
					opt[0][0] = true; opt[0][1] = true; opt[1][0] = true; opt[1][1] = true;	
					count++;
				}
			}

			if (kmap3[0][1] == 1) {		
				if ((kmap3[0][2] == 1) && (kmap3[1][1] == 1) && (kmap3[1][2] == 1)) {
					if ((opt[0][1] == false) || (opt[0][2] == false) || (opt[1][1] == false) || opt[1][2] == false) {
						opt[0][1] = true; opt[0][2] = true; opt[1][1] = true; opt[1][2] = true;		
						result[count] = "C";
						count++;
					}
				}
			}

			if (kmap3[0][2] == 1) {	
				if ((kmap3[0][3] == 1) && (kmap3[1][2] == 1) && (kmap3[1][3] == 1)) {
					if ((opt[0][2] == false) || (opt[0][3] == false) || (opt[1][2] == false) || opt[1][3] == false) {
						opt[0][2] = true; opt[0][3] = true; opt[1][2] = true; opt[1][3] = true;	
						result[count] = "B";
						count++;
					}
				}
			}

			if (kmap3[0][3] == 1) {	
				if ((kmap3[0][0] == 1) && (kmap3[1][3] == 1) && (kmap3[1][0] == 1)) {
					if ((opt[0][3] == false) || (opt[0][0] == false) || (opt[1][3] == false) || opt[1][0] == false) {
						opt[0][3] = true; opt[0][0] = true; opt[1][3] = true; opt[1][0] = true;	
						result[count] = "C'";
						count++;
					}
				}
			}

			fullyopt = true;

			for (int c = 0; c < 2; c++) {		
				for (int j = 0; j < 4; j++) {
					if (opt[c][j] == false) {
						fullyopt = false;
						break;
					}
				}
				if (!fullyopt) break;
			}

			if (!fullyopt) {	
				if ((kmap3[0][0] == 1) && (kmap3[0][1])) {		//1
					if ((opt[0][0] == false) || (opt[0][1] == false)) {
						opt[0][0] = true; opt[0][1] = true;
						result[count] = "B'A'";
						count++;
					}
				}

				if ((kmap3[0][1] == 1) && (kmap3[0][2])) {		//2
					if ((opt[0][2] == false) || (opt[0][1] == false)) {
						opt[0][2] = true; opt[0][1] = true;
						result[count] = "CA'";
						count++;
					}
				}
				if ((kmap3[0][2] == 1) && (kmap3[0][3])) {		//3
					if ((opt[0][2] == false) || (opt[0][3] == false)) {
						opt[0][2] = true; opt[0][3] = true;
						result[count] = "BA'";
						count++;
					}
				}
				if ((kmap3[0][0] == 1) && (kmap3[0][3])) {		//4
					if ((opt[0][0] == false) || (opt[0][3] == false)) {
						opt[0][0] = true; opt[0][3] = true;
						result[count] = "C'A'";
						count++;
					}
				}
				if ((kmap3[1][0] == 1) && (kmap3[1][1])) {		//5
					if ((opt[1][0] == false) || (opt[1][1] == false)) {
						opt[1][0] = true; opt[1][1] = true;
						result[count] = "B'A";
						count++;
					}
				}
				if ((kmap3[1][1] == 1) && (kmap3[1][2])) {		//6
					if ((opt[1][1] == false) || (opt[1][2] == false)) {
						opt[1][1] = true; opt[1][2] = true;
						result[count] = "CA";
						count++;
					}
				}
				if ((kmap3[1][2] == 1) && (kmap3[1][3])) {		//7
					if ((opt[1][2] == false) || (opt[1][3] == false)) {
						opt[1][2] = true; opt[1][3] = true;
						result[count] = "BA";
						count++;
					}
				}
				if ((kmap3[1][0] == 1) && (kmap3[1][3])) {		//8
					if ((opt[1][0] == false) || (opt[1][3] == false)) {
						opt[1][0] = true; opt[1][3] = true;
						result[count] = "C'A";
						count++;
					}
				}
				if ((kmap3[0][0] == 1) && (kmap3[1][0])) {		//9
					if ((opt[0][0] == false) || (opt[1][0] == false)) {
						opt[0][0] = true; opt[1][0] = true;
						result[count] = "B'C'";
						count++;
					}
				}

				if ((kmap3[1][1] == 1) && (kmap3[0][1])) {		//10
					if ((opt[1][1] == false) || (opt[0][1] == false)) {
						opt[1][1] = true; opt[0][1] = true;
						result[count] = "B'C";
						count++;
					}
				}

				if ((kmap3[0][2] == 1) && (kmap3[1][2])) {		//11
					if ((opt[0][2] == false) || (opt[1][2] == false)) {
						opt[0][2] = true; opt[1][2] = true;
						result[count] = "BC";
						count++;
					}
				}

				if ((kmap3[0][3] == 1) && (kmap3[1][3])) {		//12
					if ((opt[0][3] == false) || (opt[1][3] == false)) {
						opt[0][3] = true; opt[1][3] = true;
						result[count] = "BC'";
						count++;
					}
				}

				fullyopt = true;

				for (int c = 0; c < 2; c++) {		
					for (int j = 0; j < 4; j++) {
						if (opt[c][j] == false) {
							fullyopt = false;
							break;
						}
					}
					if (!fullyopt) break;
				}

				if (!fullyopt) {
					if (opt[0][0] == false) {		//1
						opt[0][0] = true;
						result[count] = "B'C'A'";
						count++;
					}

					if (opt[0][1] == false) {		//2
						opt[0][1] = true;
						result[count] = "B'CA'";
						count++;
					}

					if (opt[0][2] == false) {		//3
						opt[0][2] = true;
						result[count] = "BCA'";
						count++;
					}

					if (opt[0][3] == false) {		//4
						opt[0][3] = true;
						result[count] = "BC'A'";
						count++;
					}

					if (opt[1][0] == false) {		//5
						opt[1][0] = true;
						result[count] = "B'C'A";
						count++;
					}

					if (opt[1][1] == false) {		//6
						opt[1][1] = true;
						result[count] = "B'CA";
						count++;
					}

					if (opt[1][2] == false) {		//7
						opt[1][2] = true;
						result[count] = "BCA";
						count++;
					}

					if (opt[1][3] == false) {		//8
						opt[1][3] = true;
						result[count] = "BC'A";
						count++;
					}

					fullyopt = true;

					for (int c = 0; c < 2; c++) {
						for (int j = 0; j < 4; j++) {
							if (opt[c][j] == false) {
								fullyopt = false;
								break;
							}
						}
						if (!fullyopt) break;
					}
				}
			}
		}
	}


	int counter = 0;
	while (result[counter + 1] != "0") {
		cout <<"F = "<< setw(3) << result[counter] << setw(3) << "+ " << setw(3);
		counter++;
	}
	cout << result[counter] << "\n";

}}

/*vector<string> toBinary(vector<int> minterm, int vars) {
  
vector <string> storeBinary;
for (int i = 0; i < minterm.size(); i++) {
string b, newBit;
while (minterm[i] > 0) {
newBit = to_string(minterm[i] % 2);
minterm[i] = minterm[i] / 2;
b = newBit + b; 
}
  
while (b.length() != vars)
{
b = "0" + b;
}
storeBinary.push_back(b);
}

return storeBinary;
}


void lett(string a)
{
if (a[0] == '0') cout << "A'"; else if (a[0] == '1') cout << "A";
if (a[1] == '0') cout << "B'"; else if (a[1] == '1') cout << "B";
if (a[2] == '0') cout << "C'"; else if (a[2] == '1') cout << "C";

}
void letters(vector<string> min)
{
for (int i = 0; i < min.size(); i++) 
{
lett(min[i]);
if(i<min.size()-1)
cout << " + ";
}

}
*/

int main()
{
int vars, min_n;
cout << "Enter the number of variables in your function? ";
cin >> vars;
while(vars>3)
{cout<<"Enter variables up to 3 \n";
   cout << "Enter the number of variables in your function? ";
 cin>>vars;
}
cout << "Enter the number of minterms do your function have? ";
cin >> min_n;
if (min_n==0)
{	cout << "F = 0";         

}
else
{
vector<int> minterms;

int min;

cout << "Enter your minterms (press Enter after each number):" << endl;

for (int i = 0; i < min_n; i++)
{
cin >> min;
int x= pow(2, vars) - 1;
while (min <0 || min > x)
{
cout << "Invalide input. Please Enter a number again between 0 and " <<x << endl;
cin >> min;
}
minterms.push_back(min);
}

cout << "K-map is: " <<endl;
if (vars == 2) {
var2(minterms);
}
if (vars == 3) {
var3(minterms);
}

}
return 0;
}
