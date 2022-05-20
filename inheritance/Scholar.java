package com.pjatk.inheritance;

public class Scholar extends Student {

    double scholarship;

    public Scholar(String name, String surname, int yearOfBirth, String gender, String index, double scholarship) {
        super(name, surname, yearOfBirth, gender, index);
        this.scholarship=scholarship;
    }

    public void scholarInfo(){
        studentInfo();
        System.out.println("Stypendium: "+scholarship);
    }

}
