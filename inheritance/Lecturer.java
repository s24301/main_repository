package com.pjatk.inheritance;

public class Lecturer extends Person {
    protected String title;

    public Lecturer(String name, String surname, int yearOfBirth, String gender, String title) {
        super(name, surname, yearOfBirth, gender);
        this.title=title;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void lecturerInfo(){
        personInfo();
        System.out.println("Tytuł: "+title);
    }
}
