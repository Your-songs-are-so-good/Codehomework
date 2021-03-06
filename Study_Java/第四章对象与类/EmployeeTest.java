import java.time.LocalDate;

/*
 * @Descripttion: 
 * @Author: YourSongsAreSoGood
 * @Date: 2020-07-10 15:44:23
 * @LastEditors: YourSongsAreSoGood
 * @LastEditTime: 2020-07-10 16:02:38
 * @see: https://github.com/Your-songs-are-so-good
 */ 
public class EmployeeTest {
    public static void main(String[] args) {
        //fill the staff array with three Employee objects
        Employee[] staff=new Employee[3];
        
        staff[0]=new Employee("Carl Cracker", 75000, 1987, 12, 15);
        staff[1]=new Employee("Harry Hacker", 50000, 1989, 10, 1);
        staff[2]=new Employee("Tony Tester", 40000, 1990, 3, 15);

        //raise everyone's salary by 5%
        for(Employee e:staff)
            e.raiseSalary(5);
        
        //print out information about all Employee object
        for(Employee e:staff)
            System.out.println("name="+e.GetName()+",salary="+e.GetSalary()+",hireDay="+e.GetSalary());
    }
}

class Employee{
    private String name;
    private double salary;
    private LocalDate hireDay;

    public Employee(String n,double s,int year,int month,int day){
        name=n;
        salary=s;
        hireDay=LocalDate.of(year, month, day);
    }

    public String GetName(){
        return name;
    }

    public double GetSalary(){
        return salary;
    }

    public LocalDate GetHireDay(){
        return hireDay;
    }

    public void raiseSalary(double byPercent){
        double raise=salary*byPercent/100;
        salary+=raise;
    }
}