// https://www.linkedin.com/learning/c-code-challenges/calculating-next-monday-s-date?autoplay=true&resume=false
#include <stdio.h>

const char *monthes[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
const char *day_week[7] = { "Monday", "Tuesday", "wed", "thu", "fri", "sat", "sun"
    };


const int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};

char *ordinal(int v)
{
	/* catch exceptions */
	if( v==11 || v==12 || v==13 )
		return("th");

	/* everything else is consistent */
	v %= 10;
	if( v==1 )
		return("st");
	if( v==2 )
		return("nd");
	if( v==3 )
		return("rd");
	return("th");
}
int leapyear(int year)
{
	if( year%400==0 )
		return(1);
	if( year%100==0 )
		return(0);
	if( year%4==0 )
		return(1);
	return(0);
}

void getnextMonday(int dayweek,int day,int month,int year){
        int after;
        after=8-dayweek;
        day=day+after;


          if(month==2 && leapyear(year)==1 && day>(monthday[month-1]+1)){//leap year adjustment
                 day=day-monthday[month-1]-1;
                 month++;
        }

        if(day>monthday[month-1]){
            day=day-monthday[month-1];
            month++;
        }

            if(month>12){
                month=1;
                year++;
            }


        printf("Next Monday is the %d%s of %s in %d\n",day,ordinal(day),monthes[month-1],year);


}

int main()
{
    int dayweek,day,month,year;
    while(1){
        time(&now);
        today = localtime(&now);
        printf("time is %t",today);
        puts("enter day of the week");
        scanf("%d",&dayweek);
        puts("enter day");
        scanf("%d",&day);
        puts("enter month");
        scanf("%d",&month);
        puts("enter year");
        scanf("%d",&year);
        printf("Today is %s the %d%s of %s in %d\n",day_week[dayweek-1],day,ordinal(day),monthes[month-1],year);
        getnextMonday(dayweek,day,month,year);

    }
   return 0;
}
