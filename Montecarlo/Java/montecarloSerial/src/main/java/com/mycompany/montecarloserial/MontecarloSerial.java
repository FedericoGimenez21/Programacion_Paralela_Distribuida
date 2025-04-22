/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.montecarloserial;

/**
 *
 * @author Fede
 */
public class MontecarloSerial {
  public static void main(String[] args) {
    
    int n=1000000;
    double x,y,d;
    int k=0;
    for(int i=1; i<=n; i++){
      x=Math.random();
      y=Math.random();
      d=Math.sqrt(x*x+y*y);
      if(d<=1) k++;
    }
    double p=4.*k/n;
    System.out.println(p);
  }  
}