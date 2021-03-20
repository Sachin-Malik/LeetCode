class Solution {
public:
    int romanToInt(string s) 
    {
      int sum     = 0;
      int lastVal = 1000;

      for(size_t i = 0, j = s.size() ; i < j; ++i)
      {
        int val = map[s[i]];

        if(val > lastVal)
        {
          sum = sum + (val - (2 *lastVal));
        }
        else
        {
          sum = sum + val;
        }

        lastVal = val;
      }
      return sum;
    }
private:

  std::map<char, int> map = 
  {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
  };
    
};