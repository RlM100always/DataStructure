package com.example.calculator;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

import java.net.URL;
import java.util.ResourceBundle;

public class CalcController implements Initializable {

    @FXML
    private TextField display ;
    String operator=" ";
    boolean b=true ;
    double num1=0 ;
    @FXML
    public void equalButtonAction(ActionEvent event){
         double num2 =  Double.parseDouble(display.getText());

         if(operator.equals("+")){
             display.setText("Ans : "+(num2+num1));
         }
        if(operator.equals("-")){
            display.setText("Ans : "+(num1-num2));
        }
        if(operator.equals("x")){
            display.setText("Ans : "+(num2*num1));
        }
        if(operator.equals("/")){
            if(num2==0)display.setText("Invalid Operation");
            else{
                display.setText("Ans : "+(num1/num2));
            }

        }
        if(operator.equals("%")){
            display.setText("Ans : "+(num1%num2));
        }
        b=true ;
    }
    @FXML
    public void numberButtonAction(ActionEvent event){
        if(b==true){
            display.setText("");
            b=false;
        }
        String oldText =display.getText();
        String newText = ((Button) event.getSource()).getText();
        String num=oldText+newText;
        display.setText(num);

    }
    @FXML
    public void signButtonAction(ActionEvent event){
            num1=  Double.parseDouble(display.getText());
            operator= ((Button)event.getSource()).getText();
            display.setText("");
    }
    @FXML
    public void dotButtonAction(ActionEvent event){
        String old= display.getText();
        if(old.contains("."))return;
        display.setText(old+".");
    }
    @FXML
    public void ofButtonAction(){
         System.exit(1);
    }
    @FXML
    public void acButtonAction(){
        display.setText("");
    }
    @FXML
    public  void clearButtonAction(){
        String old = display.getText();
        if(old.equals(""))return ;
        String substr = old.substring(0,old.length()-1);
        display.setText(substr);
    }


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }
}
