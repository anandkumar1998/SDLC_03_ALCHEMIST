#include "unity.h"
#include "unity_internals.h"
#include "fun.h"

#define PROJECT_NAME "BUSINESS DIGITAL BOOK"
/**
 * @brief  Required by the unity test framework
 * 
 */
void setUp () {} 

void tearDown () {}

void test_p1_null (void)
{
    TEST_ASSERT_NULL(*fp);
}

void test_p2_null (void)
{
    TEST_ASSERT_NULL(*ft);
}

void test_str_eql(void)
{
    FILE *fp;
    fp=fopen("contact.dll","r");
    const char* exp_name = "Contact_Name";
    const int* exp_phone_no = 123456;
    TEST_ASSERT_EQUAL_STRING(exp_name, add_new_cont(list.name));
    TEST_ASSERT_EQUAL_INT(exp_phone_no, add_new_cont(list.phone_number));
}

void test_report_amt(void)
{
    FILE *f1 = fopen("report.csv");
    TEST_ASSERT_EQUAL(15000, report(debit_amount));
    TEST_ASSERT_EQUAL(10000, report(credit_amount));
}

void test_list_cont(void)
{
    TEST_ASSERT_TRUE_MESSAGE(list_all_contact(found) == 1, "The list of all contacts are displayed");
}

void test_del_cont(void)
{
    FILE *del;
    del = fopen("contact.csv");
    TEST_ASSERT_NOT_NULL(*del);
}


int main(){ 
    /*Initiate the Unity Test Framework*/
    UNITY_BEGIN();

    RUN_TEST(test_p1_null);
    RUN_TEST(test_p2_null);
    RUN_TEST(test_report_amt);
    RUN_TEST(test_list_cont);
    RUN_TEST(test_del_cont);
    // RUN_TEST(test_final_score);
    
   
    /*Close the Unity Test Framework*/
    return UNITY_END();
}

