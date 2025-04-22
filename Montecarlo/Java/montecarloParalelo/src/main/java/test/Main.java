/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package test;

/**
 *
 * @author Fede
 */
import model.Simulation;


public class Main {
    
    public static void main(String [] args){
        Simulation sim = new Simulation(12, 10000000);
        System.out.println(sim.pi());    
    }
}