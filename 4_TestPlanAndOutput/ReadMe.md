This directory contains all the test plans and its status of the project.



## Test Plan and Output

### Table 1 : High Level Test Plan


|ID|Description|Type of I/P | I/P | O/P | Type of Test |
|--|--|--|--|--|--|
| H01  |  Checking status of file pointer that writes the contact file  |`FILE*` type | File pointer that writes to the file | Either a NULL or undefined value | Requirement|
| H02  |   Checking status of file pointer that reads from the contact file  |`FILE*` type | File pointer that reads from the file | Either a NULL or undefined value | Requirement|
| H03  |  Equality of contact details in the Business Digital Book  |`string`& `int` type | Predefined contact info | Result of string and int value comparison | Requirement|
| H04  |  Evaluating and comparison of credit/debit transactions of the Business Digital Book  |`int` type | Credit/Debit Amount | Result of comparison with pre defined values| Requirement|
| H05  |  To obtain and verify the status of listing all the contacts  |`bool` type | status variable found | return value | Requirement|
| H06  |  Verify and test if the contact is deleted  |`FILE*` type | Pointer used to delete the file | Status of the pointer| Requirement|


### Table 2 : Low Level Test Plan

|ID|Function|Type|I/P & O/P Arguments |  Type of Test |
|--|--|--|--|--|
| L01  |   `test_p1_null`|`void` |`*fp` |  Requirement|
| L02  |   `test_p2_null`|`void` |`*ft` |  Requirement|
| L03  |   `test_str_eql`|`void` |`expected value, add_new_cont(list.values)` |  Requirement|
| L04  |   `test_report_amt`|`void` |`15000, report(credit/debit_amount)` |  Requirement|
| L05  |   `test_list_cont`|`void` |`list_all_contact(found) == 1` |  Requirement
| L06  |   `test_del_cont`|`void` |`*del` |  Requirement|
