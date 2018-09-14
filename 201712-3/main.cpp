#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<cctype>
#include<algorithm>
using namespace std;

string convert(const string &reg)
{
	string reglow(reg);
	for (string::iterator p = reglow.begin(); p != reglow.end(); ++p)
		*p = tolower(*p);
	if (reglow == "jan")return string("1");
	if (reglow == "feb")return string("2");
	if (reglow == "mar")return string("3");
	if (reglow == "apr")return string("4");
	if (reglow == "may")return string("5");
	if (reglow == "jun")return string("6");
	if (reglow == "jul")return string("7");
	if (reglow == "aug")return string("8");
	if (reglow == "sep")return string("9");
	if (reglow == "oct")return string("10");
	if (reglow == "nov")return string("11");
	if (reglow == "dec")return string("12");
	if (reglow == "sun")return string("0");
	if (reglow == "mon")return string("1");
	if (reglow == "tue")return string("2");
	if (reglow == "wed")return string("3");
	if (reglow == "thu")return string("4");
	if (reglow == "fri")return string("5");
	if (reglow == "sat")return string("6");
	return reg;
}

int month_day(int year, int month)// return the number of days in a year, month
{
	switch (month)
	{
	case 1: return 31;
	case 2: return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10:return 31;
	case 11:return 30;
	case 12:return 31;
	}
	return 0;
}

int week(int year, int month, int day)
{
	int count = 0;
	count += (year - 1970) * 365 + (year - 1973 + 4) / 4;
	for (int m = 1; m < month; m++)
	{
		count += month_day(year, m);
	}
	count += day - 1;
	return (count + 4) % 7;
}

int toi(const string &str)
{
	int ans;
	stringstream ss(str);
	ss >> ans;
	return ans;
}

string tos(int i)
{
	stringstream ss;
	ss << i;
	string s = ss.str();
	if (s.size() == 1)s = "0" + s;
	return s;
}

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	int syint = toi(s.substr(0, 4));//yyyymmHHMM
	int tyint = toi(t.substr(0, 4));
	map<string, vector<string> > table;
	for (int i = 0; i < n; i++)
	{
		string sM, sH, sd, sm, swk, scmd;
		set<int> setM, setH, setd, setm, setwk;
		int lM, rM, lH, rH, ld, rd, lm, rm, lwk, rwk;
		cin >> sM >> sH >> sd >> sm >> swk >> scmd;
		sM = sM == "*" ? "0-59" : sM;
		sH = sH == "*" ? "0-23" : sH;
		sd = sd == "*" ? "1-31" : sd;
		sm = sm == "*" ? "1-12" : sm;
		swk = swk == "*" ? "0-6" : swk;

		//deal with sm
		string::iterator b = sm.begin(), e = sm.end();
		string::iterator c = b;
		while (c != e)
		{
			c = find(b, e, ',');
			string::iterator minus = find(b, c, '-');
			if (minus == c)
			{
				lm = rm = toi(convert(string(b, c)));
				setm.insert(lm);
			}
			else
			{
				lm = toi(convert(string(b, minus)));
				rm = toi(convert(string(minus + 1, c)));
			}
			for (int i = lm; i <= rm; i++)
				setm.insert(i);
			if (c != e)b = c + 1;
		}

		//deal with sd
		c = b = sd.begin();
		e = sd.end();
		while (c != e)
		{
			c = find(b, e, ',');
			string::iterator minus = find(b, c, '-');
			if (minus == c)
			{
				ld = rd = toi(string(b, c));
				setd.insert(ld);
			}
			else
			{
				ld = toi(string(b, minus));
				rd = toi(string(minus + 1, c));
				for (int i = ld; i <= rd; i++)
				{
					setd.insert(i);
				}
			}
			if (c != e)b = c + 1;
		}

		//deal with sH
		c = b = sH.begin();
		e = sH.end();
		while (c != e)
		{
			c = find(b, e, ',');
			string::iterator minus = find(b, c, '-');
			if (minus == c)
			{
				lH = rH = toi(string(b, c));
				setH.insert(lH);
			}
			else
			{
				lH = toi(string(b, minus));
				rH = toi(string(minus + 1, c));
				for (int i = lH; i <= rH; i++)
				{
					setH.insert(i);
				}
			}
			if (c != e)b = c + 1;
		}

		//deal with sM
		c = b = sM.begin();
		e = sM.end();
		while (c != e)
		{
			c = find(b, e, ',');
			string::iterator minus = find(b, c, '-');
			if (minus == c)
			{
				lM = rM = toi(string(b, c));
				setM.insert(lM);
			}
			else
			{
				lM = toi(string(b, minus));
				rM = toi(string(minus + 1, c));
				for (int i = lM; i <= rM; i++)
				{
					setM.insert(i);
				}
			}
			if (c != e)b = c + 1;
		}

		//deal with swk
		c = b = swk.begin();
		e = swk.end();
		while (c != e && *c != '*')
		{
			c = find(b, e, ',');
			string::iterator minus = find(b, c, '-');
			if (minus == c)
			{
				lwk = rwk = toi(convert(string(b, c)));
				setwk.insert(lwk);
			}
			else
			{
				lwk = toi(convert(string(b, minus)));
				rwk = toi(convert(string(minus + 1, c)));
				for (int i = lwk; i <= rwk; i++)
				{
					setwk.insert(i);
				}
			}
			if (c != e)b = c + 1;
		}

		for (int y = syint; y <= tyint; y++)
		{
			for (set<int>::iterator m = setm.begin(); m != setm.end(); ++m)
				for (set<int>::iterator d = setd.begin(); d != setd.end(); ++d)
					if (*d <= month_day(y, *m) && setwk.count(week(y, *m, *d)) != 0)
						for (set<int>::iterator H = setH.begin(); H != setH.end(); ++H)
							for (set<int>::iterator M = setM.begin(); M != setM.end(); ++M)
								table[tos(y) + tos(*m) + tos(*d) + tos(*H) + tos(*M)].push_back(scmd);
		}
	}

	//to print
	for (map<string, vector<string> >::iterator p = table.begin(); p != table.end(); ++p)
	{
		if (p->first < t && p->first >= s)
		{
			for (size_t i = 0; i < p->second.size(); ++i)
				cout << p->first << " " << p->second[i] << endl;
		}
	}
	return 0;
}
