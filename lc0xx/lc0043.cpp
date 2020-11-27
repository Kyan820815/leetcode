//--- Q: 043. Multiply Strings

//--- method 1: back multiplication
class Solution {
public:
    string multiply(string num1, string num2) {
        string output(220, '0');
        int start = 0, output_idx;
        if (num1 == "0" || num2 == "0") return "0";
        for (int i = num1.size()-1; i>=0; --i)
        {
        	output_idx = output.size()-start-1;
			for (int j = num2.size()-1; j>=0; --j)
			{
				int num = (num1[i]-'0')*(num2[j]-'0');
				num = num + (output[output_idx]-'0');
				int rem = num%10, quo = num/10;
				output[output_idx] = rem + '0';
				output[output_idx-1] = (output[output_idx-1]-'0') + quo + '0';
				output_idx--;
			}        	
			start++;
        }
        if (output[output_idx] == '0')
        	return output.substr(output_idx+1, output.size()-output_idx-1);
    	else 
    		return output.substr(output_idx, output.size()-output_idx);
    }
};