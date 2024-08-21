======================================
Simulación de un Bucle Despachador de Eventos en C#
======================================

Este proyecto simula un sistema de eventos en C# que utiliza un **bucle despachador de eventos** para manejar suscripciones y desencadenar eventos personalizados.

**Funcionalidades Clave**

* Diseño de una clase que simula un bucle despachador de eventos.
* Definición de eventos personalizados dentro de la clase.
* Manipulación de eventos mediante suscripciones y desencadenamientos.
* Simulación de la recepción y procesamiento de mensajes utilizando eventos.

**Descripción General**

La implementación en C# simula un sistema de eventos donde un **bucle despachador de eventos** maneja múltiples suscripciones a eventos. Utiliza la funcionalidad de eventos en C# para permitir que distintas clases reaccionen a diferentes desencadenamientos. Es útil para simular:

* Sistemas de mensajería
* Sistemas de notificaciones
* Cualquier arquitectura basada en eventos

**Diseño de la Clase**

La clase principal en este diseño es el **DespachadorDeEventos**, que actúa como el centro de coordinación de eventos. Dentro de esta clase, se define un bucle que espera que ocurran eventos y luego los despacha a los suscriptores.

.. code-block:: csharp

    using System;
    using System.Collections.Generic;
    using System.Threading;

    public class DespachadorDeEventos
    {
        // Definición de un delegado y un evento personalizado
        public delegate void EventoPersonalizadoHandler(string mensaje);
        public event EventoPersonalizadoHandler EventoPersonalizado;

        // Método que simula el bucle de despacho de eventos
        public void IniciarDespachoDeEventos()
        {
            // Simulación de recepción de eventos en bucle
            while (true)
            {
                Thread.Sleep(2000); // Simula una espera entre eventos
                DispararEvento("Mensaje recibido del evento.");
            }
        }

        // Método para disparar el evento personalizado
        protected void DispararEvento(string mensaje)
        {
            // Invoca el evento si hay suscriptores
            EventoPersonalizado?.Invoke(mensaje);
        }
    }

**Explicación del Código:**

* **Delegado y Evento Personalizado:** Se define un delegado ``EventoPersonalizadoHandler`` que acepta un mensaje de tipo ``string``. El evento ``EventoPersonalizado`` permite la suscripción de métodos que manejan eventos con este formato.
* **Método `IniciarDespachoDeEventos`:** Simula un bucle infinito donde cada cierto tiempo se dispara un evento con un mensaje.
* **Método `DispararEvento`:** Desencadena el evento, notificando a todos los suscriptores con el mensaje correspondiente.

**Definición de Eventos Personalizados**

El sistema de eventos en C# permite crear eventos personalizados. Se puede definir cualquier evento usando un delegado que especifique el tipo de los datos que se desean pasar cuando el evento se desencadena.

.. code-block:: csharp

    // Definición del delegado y evento en DespachadorDeEventos
    public delegate void EventoPersonalizadoHandler(string mensaje);
    public event EventoPersonalizadoHandler EventoPersonalizado;

**Manejo de Eventos**

Las clases suscriptoras pueden manejar los eventos registrándose al evento personalizado del despachador de eventos. Se define un método que manejará el evento y se suscribe al evento para recibir notificaciones cuando se desencadene.

.. code-block:: csharp

    public class Suscriptor
    {
        public void ManejadorDeEvento(string mensaje)
        {
            Console.WriteLine("Evento manejado con el mensaje: " + mensaje);
        }
    }

    // En el Main
    DespachadorDeEventos despachador = new DespachadorDeEventos();
    Suscriptor suscriptor = new Suscriptor();

    // Suscripción al evento
    despachador.EventoPersonalizado += suscriptor.ManejadorDeEvento;

**Simulación de Mensajes y Procesamiento**

El método ``IniciarDespachoDeEventos`` dentro del ``DespachadorDeEventos`` simula la recepción de mensajes en intervalos de tiempo. Estos mensajes son enviados a todos los suscriptores, quienes luego pueden procesarlos como deseen.

**Ejemplo Completo**

.. code-block:: csharp

    using System;
    using System.Collections.Generic;
    using System.Threading;

    public class DespachadorDeEventos
    {
        public delegate void EventoPersonalizadoHandler(string mensaje);
        public event EventoPersonalizadoHandler EventoPersonalizado;

        public void IniciarDespachoDeEventos()
        {
            while (true)
            {
                Thread.Sleep(2000);
                DispararEvento("Mensaje recibido del evento.");
            }
        }

        protected void DispararEvento(string mensaje)
        {
            EventoPersonalizado?.Invoke(mensaje);
        }
    }

    public class Suscriptor
    {
        public void ManejadorDeEvento(string mensaje)
        {
            Console.WriteLine("Evento manejado con el mensaje: " + mensaje);
        }
    }

    class Program
    {
        static void Main()
        {
            DespachadorDeEventos despachador = new DespachadorDeEventos();
            Suscriptor suscriptor = new Suscriptor();

            despachador.EventoPersonalizado += suscriptor.ManejadorDeEvento;

            // Ejecuta el bucle de despacho de eventos en un hilo separado
            Thread threadDespachador = new Thread(despachador.IniciarDespachoDeEventos);
            threadDespachador.Start();
        }
    }

**Explicación Completa:**

1. **DespachadorDeEventos:** Simula un bucle que recibe eventos y los despacha.
2. **Suscriptor:** Clase que reacciona a los eventos disparados por el despachador.
3. **IniciarDespachoDeEventos:** Bucle que genera eventos simulados cada 2 segundos.
4. **Suscripción al Evento:** El suscriptor se registra al evento y procesa los mensajes recibidos.