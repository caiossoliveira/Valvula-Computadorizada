package controller;

import gnu.io.CommPortIdentifier;
import gnu.io.NoSuchPortException;
import gnu.io.SerialPort;
import java.io.OutputStream;
import javax.swing.JOptionPane;

/**
 *
 * @author Caio Oliveira [caiossoliveira@gmail.com]
 */
public class ControleSerial {
    
    private OutputStream saidaSerial;
    private int taxa;
    private String portaCom;
    private SerialPort sPorta;

    public ControleSerial(int taxa, String portaCom) {
        this.taxa = taxa;
        this.portaCom = portaCom;
        this.iniciar();
    }
    
    private void iniciar(){
        try {
            CommPortIdentifier portId = null;
            try {
                portId = CommPortIdentifier.getPortIdentifier(this.portaCom);
            } catch (NoSuchPortException npe) {
                JOptionPane.showMessageDialog(null, "Porta COM não encontrada.");
            }
            
            sPorta = (SerialPort) portId.open("Comunicação serial", this.taxa);
            saidaSerial = sPorta.getOutputStream();
            sPorta.setSerialPortParams(this.taxa, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void enviarDado(String dado){
        try {
            saidaSerial.write(dado.getBytes());
            System.out.println(dado);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Erro ao enviar dado");
            System.out.println("Valvula Computadorizada - controleSerial - enviarDaio()" + e.getMessage());
        }
    }
    
    public void desconectar(){
        if (sPorta != null){
            try {
                saidaSerial.close();
            } catch (Exception e) {
                System.out.println("Erro ao desconectar.");
            }
            sPorta.close();
        }
    }
    
    
    
    
    
}
