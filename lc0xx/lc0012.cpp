//--- Q: 012. Integer to Roman

//--- method 1: elegant solution, better
class Solution {
public:
    string intToRoman(int num) {
        string table[4][10] = { {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                                {"", "M", "MM", "MMM"}};
        int rem, count=0;
        string out;
        while(num != 0)
        {            
            out = table[count++][num % 10] + out;
            num = num / 10;
        }
        return out;
    }
};

//--- method 2: digit by digit processing
class Solution {
public:
    string intToRoman(int num) {
    	int rem, digit = 0;
    	string out;

    	while(num != 0)
    	{
    		rem = num % 10;
    		num = num / 10;

			while(rem > 0)
			{
				if (rem == 9)
				{
					out = rom(10*pow(10,digit)) + out;
					out = rom(pow(10,digit)) + out;
					rem = 0;
				}
				else if (rem == 5)
				{
					out = rom(5*pow(10,digit)) + out;
					rem = 0;
				}
				else if (rem == 4)
				{
					out = rom(5*pow(10,digit)) + out;
					out = rom(pow(10,digit)) + out;
					rem = 0;
				}
				else
				{
					out = rom(pow(10,digit)) + out;
					rem--;
				}
			}
    		digit++;
    	}

    	return out;
    }

    char rom(int num) {
    	switch (num)
    	{
    		case 1:
    			return 'I';
    		case 5:
    			return 'V';
    		case 10:
    			return 'X';
    		case 50:
    			return 'L';
    		case 100:
    			return 'C';
    		case 500:
    			return 'D';
    		case 1000:
    			return 'M';
    		default:
    			return '0';
    	}
    }
};