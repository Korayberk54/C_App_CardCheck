#include <cs50.h>
#include <stdio.h>


long card_number;
long card_copy;
bool valid = true;
int pos = 0;
int check_sum = 0;

bool is_valid();
long get_card_number();



int main()
{
    get_card_number();
}

long get_card_number()
{
        // Get a number to check if it is valid or not while is_valid is false.
    do
    {
     card_number = get_long("Number: ");
     card_copy = card_number;
     pos = 0;
     check_sum = 0;
    }
    while(!is_valid());
    
    return card_number;
    return card_copy;
}

bool is_valid()
{
    while (card_number != 0)  // run the program untill card number reduces to 0 to check if Luhn applies or not 
    {
        if ( pos % 2 != 0) // odd indixes
        {
            if ( card_number % 10 > 4)
            {
                check_sum += (2 * (card_number % 10) / 10) + (2* (card_number %10) %10);
            }
            else // even indexes
            {
                check_sum += 2 * (card_number % 10);
            }
        }
        
        else
        {
            check_sum += card_number % 10;
        }
        
        pos++;
        
        card_number /= 10;
    }
    
    if (check_sum %10 == 0)
    {         
        // compare digit lengths and starting numbers to decide if its a VISA , AMEX or MasterCard AND return true or false 
        // depending on comparison
        
        long amex_head = card_copy / 10000000000000;
        long master_card_head = card_copy / 100000000000000;
        long visa_head = card_copy / 1000000000000;
        
        
        if ( pos == 15 && (amex_head == 34 || amex_head == 37))
        {
            printf("AMEX\n");
            valid = true;
            return valid;
        }
        
        if ( pos == 16 && (master_card_head >= 51 && master_card_head <= 55))
        {
            printf("MASTERCARD\n");
            valid = true;
            return valid;
        }
        if (( pos == 13 && visa_head == 4) || ( pos == 16 && master_card_head / 10 == 4))
        {
            printf("VISA\n");
            valid = true;
            return valid;
        }
        printf("INVALID\n");
        return valid;
    }
    else
    {
        printf("INVALID\n");
        valid = false;
        return valid;
    }
    
}


