# cub3d📌 Pasos a implementar
Abrir el archivo y leerlo línea por línea (get_next_line).

Eliminar espacios innecesarios (trim).

Determinar el tipo de dato:

Si la línea empieza con NO, SO, WE, EA → Es una textura.

Si la línea empieza con F o C → Es un color.

Validar y almacenar los datos correctamente en la estructura.

Manejar errores genéricos:

"Error en texturas" si hay problemas con las rutas.

"Error en color" si los valores no están en 0-255.

"Error en mapa" (más adelante).

📌 Funciones principales
✅ parse_data(fd) → Función principal que maneja el parsing.
✅ validate_color(line, &color) → Extrae y valida valores de color.
✅ unite(color_str) → Convierte "255,255,255".
✅ trim(line) → Limpia espacios y tabulaciones.