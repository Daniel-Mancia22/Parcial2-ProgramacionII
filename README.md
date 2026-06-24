# Parcial II - Programación II

## Descripción

Este proyecto corresponde a la sección práctica (70%) del **Segundo Parcial de Programación II**. Consiste en una aplicación de consola desarrollada en **C++** utilizando el IDE **Code::Blocks**, diseñada para la gestión automatizada de préstamos bancarios, registro de pagos y consulta de información de clientes, empleados y préstamos. Implementa **programación orientada a objetos (POO)** con herencia, polimorfismo y composición de clases.

---

## Funcionalidades Principales

### **Gestión de Préstamos (Opción 1 y 4)**
- **Creación de Préstamo:** Solicita el ID del cliente y el código del ejecutivo de crédito, realizando una búsqueda en los arreglos predefinidos. Solo si ambos existen, se capturan el ID del préstamo, monto, plazo y fecha para crear el objeto `Prestamo`.
- **Validación de Existencia:** Si el cliente o el ejecutivo no se encuentran, se muestra un mensaje de error y se deniega la operación, regresando al menú principal.
- **Detalle Completo:** Opción dedicada a consultar la información completa de un préstamo específico, incluyendo su historial de pagos (número de cuota, fecha y monto).

### **Registro de Pagos (Opción 2)**
- **Búsqueda por ID:** Localización del préstamo objetivo mediante su código único.
- **Amortización:** Captura del número de cuota, fecha y monto del pago. El cajero que atiende se busca en el arreglo de empleados. El pago se registra en el préstamo y disminuye el saldo pendiente.
- **Validación de Cajero:** Si el ID del cajero no existe, se muestra un mensaje de error y se cancela el registro.

### **Visualización de Préstamos (Opción 3)**
- **Listado General:** Muestra una tabla resumida con ID del préstamo, nombre del cliente y monto aprobado de todos los préstamos registrados.

---

## Tecnologías y Herramientas Utilizadas

### Entorno y Lenguaje
- **C++** - Lenguaje base enfocado en Programación Orientada a Objetos (POO).
- **Code::Blocks** - Entorno de Desarrollo Integrado (IDE) utilizado para la escritura, compilación y depuración del código fuente (`.cbp`, `.depend`, `.layout`).
- **GNU GCC Compiler** - Compilador estándar empleado para la generación del ejecutable.

### Arquitectura de Software
- **Modularidad (Archivos de Cabecera):** Separación de responsabilidades mediante clases independientes estructuradas en archivos `.h`:
  - `Persona.h`: Clase base con atributos comunes (`codigo`, `nombre`, `apellido`).
  - `Cliente.h`: Clase abstracta que hereda de `Persona`, con el método virtual puro `getTipoCliente()`.
  - `ClientePersonaNatural.h` y `ClientePersonaJuridica.h`: Subclases concretas que implementan `getTipoCliente()` (retorna `1` y `2` respectivamente).
  - `Empleado.h`: Clase abstracta que hereda de `Persona`, con el método virtual puro `getNombrePuesto()`.
  - `Ejecutivo.h` y `Cajero.h`: Subclases concretas que implementan `getNombrePuesto()` (`"Ejecutivo"` y `"Cajero"`).
  - `Prestamo.h`: Clase compuesta que contiene objetos `Cliente`, `Ejecutivo`, `Fecha` y un arreglo de `Pago`.
  - `Pago.h`: Clase compuesta que contiene objetos `Fecha` y `Cajero`.
  - `Fecha.h`: Clase utilitaria para la gestión estandarizada de fechas.
- **Herencia y Polimorfismo:** `Cliente` y `Empleado` heredan de `Persona`; sus subclases sobrescriben métodos virtuales puros.
- **Composición:** `Prestamo` contiene referencias a `Cliente`, `Ejecutivo`, `Fecha` y un arreglo de `Pago*`. `Pago` contiene referencias a `Fecha` y `Cajero`.
- **Flujo de Consola Principal (`main.cpp`):** Controlador centralizado con datos predefinidos, un ciclo interactivo (`do-while`) y evaluación de opciones mediante estructura condicional (`switch-case`).

---

## Jerarquía de Clases

```
Persona
 ├── Cliente (abstracta)
 │    ├── ClientePersonaNatural
 │    └── ClientePersonaJuridica
 └── Empleado (abstracta)
      ├── Ejecutivo
      └── Cajero

Prestamo ─── compone ──→ Cliente, Ejecutivo, Fecha, Pago[]
Pago     ─── compone ──→ Fecha, Cajero
```

---

## Descripción de Clases

### Persona
- **Atributos:** `codigo` (int), `nombre` (string), `apellido` (string)
- **Métodos:** `getCodigo()`, `getNombreCompleto()`

### Cliente : Persona (abstracta)
- **Atributos adicionales:** `nit` (string)
- **Métodos:** `setNit()`, `getNit()`, `getTipoCliente()` (virtual puro)
- **Subclases:**
  - **ClientePersonaNatural** — atributos: `dui` (string), `fechaNac` (Fecha*); `getTipoCliente()` retorna `1`
  - **ClientePersonaJuridica** — atributos: `representanteLegal` (Persona*); `getTipoCliente()` retorna `2`

### Empleado : Persona (abstracta)
- **Atributos adicionales:** `sueldo` (float)
- **Métodos:** `setSueldo()`, `getSueldo()`, `getNombrePuesto()` (virtual puro)
- **Subclases:**
  - **Ejecutivo** — atributos: `carteraAsignada` (int); `getNombrePuesto()` retorna `"Ejecutivo"`
  - **Cajero** — atributos: `cajaAsignada` (int); `getNombrePuesto()` retorna `"Cajero"`

### Prestamo
- **Atributos:** `idPrestamo` (int), `plazo` (int), `cuota` (float), `cliente` (Cliente*), `ejecutivoCredito` (Ejecutivo*), `fecha` (Fecha*), `montoAprobado` (float), `listaPagos[]` (Pago*), `saldoPendiente` (float), `contadorPagos` (int)
- **Constructor:** recibe `idPrestamo`, `plazo`, `montoAprobado`. Calcula `cuota = montoAprobado / plazo` e inicializa `saldoPendiente = montoAprobado`.
- **Métodos principales:**
  - `registrarPago(Pago*)` — agrega un pago al arreglo y descuenta el monto del saldo pendiente
  - `getCliente()`, `getEjecutivo()`, `getFecha()`
  - `getListaPagos()`, `getContadorPagos()`
  - `getSaldoPendiente()`, `getCuota()`, `getPlazo()`, `getMontoAprobado()`
  - `getIdPrestamo()`

### Pago
- **Atributos:** `numeroCuota` (int), `fechaPago` (Fecha*), `monto` (float), `cajeroAtendio` (Cajero*)
- **Métodos:** `getNumeroCuota()`, `getFechaPago()`, `getMonto()`, `getCajeroAtendio()`, `setCajeroAtendio(Cajero*)`

### Fecha
- **Atributos:** `dia` (int), `mes` (int), `anio` (int)
- **Métodos:** `mostrarFecha()` — retorna `"dd/mm/aaaa"`

---

## Funcionalidades del Menú

| Opción | Descripción |
|--------|-------------|
| 1 | Agregar nuevo préstamo (requiere ID de cliente y ejecutivo) |
| 2 | Registrar pago a un préstamo (requiere ID de préstamo y cajero) |
| 3 | Mostrar lista resumida de préstamos (ID, cliente, monto) |
| 4 | Mostrar detalle completo de un préstamo (incluye pagos realizados) |
| 5 | Salir del programa |

---

## Flujo de la Aplicación

### Ciclo del Menú de Opciones
Al ejecutar el programa, se cargan los datos predefinidos (4 empleados y 4 clientes) y se despliega un menú interactivo con las siguientes opciones:

1. **Agregar nuevo préstamo** → Busca cliente y ejecutivo por ID; si existen, captura datos del préstamo (ID, monto, plazo, fecha) y lo almacena en el arreglo.
2. **Registrar pago** → Busca préstamo por ID; si existe, captura número de cuota, fecha, monto y busca el cajero por ID; crea el `Pago` y lo registra en el préstamo.
3. **Mostrar lista de préstamos** → Itera el arreglo de préstamos y muestra ID, cliente y monto de cada uno.
4. **Mostrar detalle de préstamo** → Busca préstamo por ID y muestra toda la información incluyendo el historial de pagos.
5. **Salir** → Finaliza la ejecución del programa.

---

## Validaciones y Reglas de Negocio

- **Verificación Estricta de Clientes y Empleados:** No se puede otorgar un préstamo si el ID del cliente o del ejecutivo no existe en los arreglos predefinidos.
- **Verificación de Cajero:** No se puede registrar un pago si el ID del cajero no existe en el arreglo de empleados.
- **Cálculo de Cuota:** La cuota se calcula automáticamente como `montoAprobado / plazo` en el constructor de `Prestamo`.
- **Saldo Pendiente:** Inicialmente igual al monto aprobado. Se reduce con cada pago registrado mediante el método `registrarPago()`.
- **Dimensión Controlada:** El arreglo de préstamos tiene un límite máximo de 4 elementos (`#define TAM 4`). Si se alcanza el límite, se muestra el mensaje "La lista está llena" y se deniega la operación.
- **Datos Predefinidos:** Los clientes (2 personas naturales y 2 personas jurídicas) y empleados (2 ejecutivos y 2 cajeros) están precargados en el código y no se capturan en tiempo de ejecución.

---

## Datos Precargados

### Empleados
| Código | Nombre | Apellido | Puesto | Cartera/Caja |
|--------|--------|----------|--------|--------------|
| 1 | JOSUE | CRAMOS | Ejecutivo | Cartera 1 |
| 2 | JUAN | PEREZ | Ejecutivo | Cartera 2 |
| 1 | JOSE | GUZMAN | Cajero | Caja 1 |
| 2 | ROSA | GUTIERREZ | Cajero | Caja 2 |

### Clientes
| Código | Nombre | Tipo |
|--------|--------|------|
| 1 | MANUEL RIVAS | Persona Natural |
| 2 | JULIA MARTINEZ | Persona Natural |
| 1 | REPUESTOS RIVAS | Persona Jurídica |
| 2 | REPUESTOS MARTINEZ | Persona Jurídica |

---

## Estructura del Proyecto

```
Parcial2/
 ├── Cajero.h
 ├── Cliente.h
 ├── ClientePersonaJuridica.h
 ├── ClientePersonaNatural.h
 ├── Ejecutivo.h
 ├── Empleado.h
 ├── Fecha.h
 ├── main.cpp
 ├── Pago.h
 ├── Parcial2.cbp
 ├── Parcial2.depend
 ├── Parcial2.layout
 ├── Persona.h
 ├── Prestamo.h
 ├── indicaciones.jpg
 ├── indicaciones2.jpg
 ├── .gitignore
 ├── bin/
 │   └── Debug/
 └── obj/
     └── Debug/
```

---

## Desarrollador
- [Daniel Mancia](https://github.com/Daniel-Mancia22) - Backend Developer

---

## Notas del Proyecto

- **Propósito Académico:** Desarrollado y defendido como solución práctica correspondiente al 70% de la nota del **Segundo Parcial** de la materia **Programación II**.
- **Formato de Fecha:** El ingreso de fechas se realiza con día, mes y año separados por espacio o Enter (ej: `15 06 2026`), sin barras.
- **Macro TAM:** La macro `#define TAM 4` define el tamaño máximo de los arreglos de préstamos y pagos.
- **Archivos Code::Blocks:** `*.depend` y `*.layout` son generados automáticamente por el IDE.
- **Enfoque de Modularidad:** Implementación limpia de encapsulamiento, herencia, polimorfismo y composición utilizando buenas prácticas de programación en C++.
