    void calibrateServo() 
    //to calibrate the servo sweep pulsewidths from 0.0003 to 0.0025 seconds. find the extreme values and then find the middle pulsewidth.
{
    
    float time = 0.00145;
    myled = !myled;
    wait(1);
    while ( time < SERVO_PERIOD )
    {   
       
        servo.pulsewidth(time);
        myled = !myled;
        wait(1);
        if (pc.getc()) pc.printf("%f\n",time);
        
        time = time + 0.00001;
    }
    pc.printf("Error\n");

}
