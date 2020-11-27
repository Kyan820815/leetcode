//--- Q: 013. Roman to Integer

//--- method 1-1: switch case for definition, better
class Solution {
public:
    int romanDef(char c) {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        for (int idx = 0; idx < s.length(); idx++)
        {
            if ( idx < s.length()-1 && romanDef(s[idx]) < romanDef(s[idx+1]))
                sum -= romanDef(s[idx]);
            else
                sum += romanDef(s[idx]);
        }
        return sum;
    }
};

//--- method 1-2: switch case left to right
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int idx = 0; idx < s.length(); idx++)
        {
            switch (s[idx])
            {
                case 'I':
                    if (idx < s.length()-1 && (s[idx+1]=='V' || s[idx+1]=='X'))
                        sum -= 1;
                    else
                        sum += 1;
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if (idx < s.length()-1 && (s[idx+1]=='L' || s[idx+1]=='C'))
                        sum -= 10;
                    else
                        sum += 10;
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if (idx < s.length()-1 && (s[idx+1]=='D' || s[idx+1]=='M'))
                        sum -= 100;
                    else
                        sum += 100;
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
                default:
                    break;
            }
        }
        return sum;
    }
};

//--- method 1-3: switch case right to left
class Solution {
public:
    int romanToInt(string s) {
    	int sum = 0;
        for (int idx = s.length()-1; idx >= 0; idx--)
        {
        	switch (s[idx])
        	{
        		case 'I':
        			sum = sum+1;
        			break;
        		case 'V':
        			sum += 5;
        			if (idx > 0 && s[idx-1] == 'I')
        			{
        				sum -= 1;
        				idx--;
        			}
        			break;
        		case 'X':
        			sum += 10;
        			if (idx > 0 && s[idx-1] == 'I')
        			{
        				sum -= 1;
        				idx--;
        			}
        			break;
        		case 'L':
        			sum += 50;
        			if (idx > 0 && s[idx-1] == 'X')
        			{
        				sum -= 10;
        				idx--;
        			}
        			break;
        		case 'C':
        			sum += 100;
        			if (idx > 0 && s[idx-1] == 'X')
        			{
        				sum -= 10;
        				idx--;
        			}
        			break;
        		case 'D':
        			sum += 500;
        			if (idx > 0 && s[idx-1] == 'C')
        			{
        				sum -= 100;
        				idx--;
        			}
        			break;
        		case 'M':
        			sum += 1000;
        			if (idx > 0 && s[idx-1] == 'C')
        			{
        				sum -= 100;
        				idx--;
        			}
        			break;
        		default:
        			break;
        	}
        }
        return sum;
    }
};

//--- method 2: map
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char,int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

        for (int idx = 0; idx < s.length(); idx++)
        {
            if ( idx < s.length()-1 && romanMap[s[idx]] < romanMap[s[idx+1]])
                sum -= romanMap[s[idx]];
            else
                sum += romanMap[s[idx]];

        }
        return sum;
    }
};