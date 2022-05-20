package com.edu.pjatk.model;

public enum TypeOfCustomer {
    COMPANY("company"), PRIVATE("private person");

    private String type;
    TypeOfCustomer(String type){
        this.type=type;
    }

    public String getType(){
        return type;
    }


}
