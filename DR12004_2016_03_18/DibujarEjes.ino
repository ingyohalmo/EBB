void DibujarEjes(){
//Dibuja lineas de referencia del voltaje
  display.drawLine( 10, 0, 10, 47, BLACK);
  display.drawLine( 5, 47-(.166 *1023.0 * scale), 10, 47-(.166 *1023.0 * scale), BLACK);
  display.drawLine( 0, 47-(.33 *1023.0 * scale), 10, 47-(.33 *1023.0 * scale), BLACK);
  display.drawLine( 5, 47-(.5 *1023.0 * scale), 10, 47-(.5 *1023.0 * scale), BLACK);
  display.drawLine( 0, 47-(.66 *1023.0 * scale), 10, 47-(.66 *1023.0 * scale), BLACK);
  display.drawLine( 5, 47-(.84 *1023.0 * scale), 10, 47-(.84 *1023.0 * scale), BLACK);
}
