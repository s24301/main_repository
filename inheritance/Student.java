package com.pjatk.inheritance;

public class Student extends Person {
    protected String index;

    public Student(String name, String surname, int yearOfBirth, String gender, String index) {
        super(name, surname, yearOfBirth, gender);
        this.index=index;
    }

    public String getIndex() {
        return index;
    }

    public void setIndex(String index) {
        this.index = index;
    }

    public void studentInfo(){
        personInfo();
        System.out.println("Indeks: "+index);
    }
}
