class Solution {
public:
    string intToRoman(int num) {
        string str="";
        if(num>=1000)
        {
            int a=num/1000;
            for(int i=0;i<a;i++)
                str+="M";
            num%=1000;
        }
         if(num>=900)
        {
            str+="CM";
            num-=900;
        }
         if(num>=500)
        {
            str+="D";
            num-=500;
        }
         if(num>=400)
        {
            str+="CD";
            num-=400;
        }
         if(num>=100)
        {
            int a=num/100;
            for(int i=0;i<a;i++)
                str+="C";
            num%=100;
        }
         if(num>=90)
        {
            str+="XC";
            num-=90;
        }
         if(num>=50)
        {
            str+="L";
            num-=50;
        }
         if(num>=40)
        {
            str+="XL";
            num-=40;
        }
         if(num>=10)
        {
            int a=num/10;
            for(int i=0;i<a;i++)
                str+="X";
            num%=10;
        }
         if(num>=9)
        {
            str+="IX";
            num-=9;
        }
         if(num>=5)
        {
            str+="V";
            num-=5;
        }
         if(num>=4)
        {
            str+="IV";
            num-=4;
        }
         if(num>=1)
        {
            int a=num;
            for(int i=0;i<a;i++)
                str+="I";
            
        }
        
        return str;
    }
};