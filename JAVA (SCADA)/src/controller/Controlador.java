package controller;

/**
 * @author Caio Oliveira [caiossoliveira@gmail.com]
 */
public class Controlador {
    
    //controleSerial cs = new ControleSerial(9600, "com3");
    
    private ControleSerial arduino;

    public Controlador(int taxa, String porta) {
        arduino = new ControleSerial(9600, porta);
    }
   
    
    public void comunicacao(String dado){
        arduino.enviarDado(dado);
        arduino.desconectar();
        
        System.out.println("Dado enviado e comunicação desconectada.");
    }   
}
