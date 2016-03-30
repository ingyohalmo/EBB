void DibujarEjes(){
//Dibuja lineas de referencia del voltaje
  display.drawLine( 42, 0, 42, 48, BLACK);
  display.drawLine( 37, 47-(.166 *1023.0 * scale), 47, 47-(.166 *1023.0 * scale), BLACK);
  display.drawLine( 37, 47-(.33 *1023.0 * scale), 47, 47-(.33 *1023.0 * scale), BLACK);
  display.drawLine( 37, 47-(.5 *1023.0 * scale), 47, 47-(.5 *1023.0 * scale), BLACK);
  display.drawLine( 37, 47-(.66 *1023.0 * scale), 47, 47-(.66 *1023.0 * scale), BLACK);
  display.drawLine( 37, 47-(.84 *1023.0 * scale), 47, 47-(.84 *1023.0 * scale), BLACK);
}
