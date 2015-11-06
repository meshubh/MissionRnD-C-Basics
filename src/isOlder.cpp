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
int check_valid(int, int, int, int, int, int);
int isOlder(char *dob1, char *dob2)
{
	int date1=0, month1=0, year1=0, date2=0, month2=0, year2=0,valid=0;
	date1 = (*(dob1)-48) * 10 + *(dob1 + 1) - 48;
	month1 = (*(dob1 + 3) - 48) * 10 + *(dob1 + 4) - 48;
	year1 = ((*(dob1 + 6) - 48) * 1000 + (*(dob1 + 7) - 48) * 100 + (*(dob1 + 8) - 48) * 10 + *(dob1 + 9) - 48);
	date2 = (*(dob2)-48) * 10 + *(dob2 + 1) - 48;
	month2 = (*(dob2 + 3) - 48) * 10 + *(dob2 + 4) - 48;
	year2 = ((*(dob2 + 6) - 48) * 1000 + (*(dob2 + 7) - 48) * 100 + (*(dob2 + 8) - 48) * 10 + (*(dob2 + 9) - 48));
	valid = check_valid(date1, month1, year1, date2, month2, year2);
	if (valid == 0)
	{
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
	else
		return -1;
}
int check_valid(int date1, int month1, int year1, int date2, int month2, int year2)
{
	if (year1 <= 0 || year2 <= 0 || month1 <= 0 || month1 > 12 || month2 <= 0 || month2 > 12 || date1 <= 0 || date2 <= 0)
		return 1;
	if (year1 > 2015 || year2 > 2015)
		return 0;
	else if (month1 == 2 && month2 == 2)
	{
		if (year1 % 4 == 0 && year2 % 4 == 0)
		{
			if (date1 <= 29 && date2 <= 29)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 == 0)
		{
			if (date2 <= 29 && date1 <= 28)
				return 0;
			else
				return 1;
		}
		else if (year1%4==0)
		{
			if (date1 <= 29 && date1 <= 28)
				return 0;
			else
				return 1;
		}
		else
		{
			if (date1 <= 28 && date2 <= 28)
				return 0;
			else
				return 1;
		}
	}
	else if (month1 == 2)
	{
		if (year1 % 4 == 0 && month2 <= 7 && month2 % 2 == 1)
		{
			if (date1 < 29 && date2 < 31)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 == 0 && month2  > 7 && month2 % 2 == 0)
		{
			if (date1 < 29 && date2 < 31)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 == 0 && month2 <= 7 && month2 % 2 == 0)
		{
			if (date1 < 29 && date2 < 30)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 == 0 && month2 > 7 && month2 % 2 == 1)
		{
			if (date1 < 29 && date2 < 30)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 != 0 && month2 <= 7 && month2 % 2 == 1)
		{
			if (date1 < 28 && date2 < 31)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 != 0 && month2 > 7 && month2 % 2 == 0)
		{
			if (date1 < 28 && date2 < 31)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 != 0 && month2 <= 7 && month2 % 2 == 0)
		{
			if (date1 < 28 && date2 < 30)
				return 0;
			else
				return 1;
		}
		else if (year1 % 4 != 0 && month2 > 7 && month2 % 2 == 1)
		{
			if (date1 < 28 && date2 < 30)
				return 0;
			else
				return 1;
		}
	}
	else if (month2 == 2)
	{
		if (year2 % 4 == 0 && month1 <= 7 && month1 % 2 == 1)
		{
			if (date2 <= 29 && date1 <= 31)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 == 0 && month1  > 7 && month1 % 2 == 0)
		{
			if (date2 <= 29 && date1 <= 31)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 == 0 && month1 <= 7 && month1 % 2 == 0)
		{
			if (date2 <= 29 && date1 <= 30)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 == 0 && month1 > 7 && month1 % 2 == 1)
		{
			if (date2 <= 29 && date1 <= 30)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 != 0 && month1 <= 7 && month1 % 2 == 1)
		{
			if (date2 <= 28 && date1 <= 31)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 != 0 && month1 > 7 && month1 % 2 == 0)
		{
			if (date2 <= 28 && date1 <= 31)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 != 0 && month1 <= 7 && month1 % 2 == 0)
		{
			if (date2 <= 28 && date1 <= 30)
				return 0;
			else
				return 1;
		}
		else if (year2 % 4 != 0 && month1 > 7 && month1 % 2 == 1)
		{
			if (date2 <= 28 && date1 <= 30)
				return 0;
			else
				return 1;
		}
	}
	else if (month1 <=7 && month1 % 2 == 1 && month2 <= 7 && month2 % 2 == 1)
	{
		if (date1 <= 31 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 1 && month2 > 7 && month2 % 2 == 0)
	{
		if (date1 <= 31 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 0 && month2 <= 7 && month2 % 2 == 1)
	{
		if (date1 <= 31 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 0 && month2 > 7 && month2 % 2 == 0)
	{
		if (date1 <= 31 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 0 && month2 <= 7 && month2 % 2 == 1)
	{
		if (date1 <= 30 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 0 && month2 > 7 && month2 % 2 == 0)
	{
		if (date1 <= 30 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 1 && month2 <= 7 && month2 % 2 == 1)
	{
		if (date1 <= 30 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 1 && month2 > 7 && month2 % 2 == 0)
	{
		if (date1 <= 30 && date2 <= 31)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 1 && month2 <= 7 && month2 % 2 == 0)
	{
		if (date1 <= 31 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 1 && month2 > 7 && month2 % 2 == 1)
	{
		if (date1 <= 31 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 0 && month2 <= 7 && month2 % 2 == 0)
	{
		if (date1 <= 31 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 0 && month2 > 7 && month2 % 2 == 1)
	{
		if (date1 <= 31 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 0 && month2 <= 7 && month2 % 2 == 0)
	{
		if (date1 <= 30 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 <= 7 && month1 % 2 == 0 && month2 > 7 && month2 % 2 == 1)
	{
		if (date1 <= 30 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 1 && month2 <= 7 && month2 % 2 == 0)
	{
		if (date1 <= 30 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else if (month1 > 7 && month1 % 2 == 1 && month2 > 7 && month2 % 2 == 1)
	{
		if (date1 <= 30 && date2 <= 30)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}