/*
Customer/User Records:
    EmailID        Country       State           City
    ab1@gmail.com   IN          Telanagana      Hyderabad   
    ab2@gmail.com   IN          Telanagana      Warangal   
    ab3@gmail.com   IN          Maharashtra      Mumbai
    ab4@gmail.com   US          Washington       W DC
    ab5@gmail.com   SL          Some State       Some City
    .
    .
    .
    .
    Lacs of users.
    
CustomerCare:
    EID  Country       State           City             
    11   IN          Telanagana      Hyderabad 
    11   IN          Telanagana      Warangal
    11   US          Washington       W DC
    33   IN          Maharashtra      *
    33   IN          Maharashtra      !Nagpur
    33   IN          Maharashtra      !Pune
    33   SL          *                *
    22   IN          *                *
    99   *           *                *

* = All Allowed
! = Not allowed
When a customer care guy signs in, find out all customers with whom he can interact with.

1. Pick any data structure of your choice. Assume the data is already populated.
2. Take List of CustomerRecords, EmployeeIDRecords, One EmployeeID. You have to return the list of 
   EmailIDs with whom the employee can interact with.
*/


