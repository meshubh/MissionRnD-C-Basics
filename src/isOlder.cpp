/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) 
{
	int date1, month1, year1, date2, month2, year2;
	date1 = (*(dob1) - 48) * 10 + *(dob1 +1)-48;
	month1 = ((*dob1 + 3) - 48) * 10 + *(dob1 + 4) - 48;
	year1 = ((*dob1 + 6) - 48) * 1000 + (*(dob1 + 7) - 48) * 100 + (*(dob1 + 8) - 48) * 10 + *(dob1 + 9) - 48;
	date2 = (*(dob2)-48) * 10 + *(dob2 + 1) - 48;
	month2 = ((*dob2 + 3) - 48) * 10 + *(dob2 + 4) - 48;
	year2 = ((*dob2 + 6) - 48) * 1000 + (*(dob2 + 7) - 48) * 100 + (*(dob2 + 8) - 48) * 10 + *(dob2 + 9) - 48;
	if (date1 > 31 || date2 > 31 || month1 > 12 || month2 > 12 || year1 > 9999 || year2 > 9999)
		return -1;
	if (year1 > year2)
		return 2;
	else if (year2 > year1)
		return 1;
	else
	{
		if (month1 > month2)
			return 2;
		else if (month2 > month1)
			return 1;
		else
		{
			if (date1 > date2)
				return 2;
			else if (date2 > date1)
				return 1;
			else
				return 0;
		}
	}
}
