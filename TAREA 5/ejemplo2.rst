======================================
Análisis del Código: Event Dispatcher en C#
======================================

Este proyecto implementa un **Despachador de Eventos** en C#, siguiendo un patrón de diseño basado en la suscripción y el despacho de eventos. 

**Funcionalidades Clave**

* Simulación de un sistema de eventos que permite suscribir, desuscribir y despachar eventos.
* Definición de un despachador de eventos con capacidad para múltiples manejadores.
* Uso de un evento global que maneja todas las operaciones de despacho.
* Simulación del procesamiento de eventos mediante un retardo.

**Descripción General**

El código simula un sistema de eventos basado en el patrón de **suscripción y despacho de eventos**. Se pueden registrar múltiples manejadores a eventos específicos. Además, existe un manejador global que responde a cualquier evento despachado.

**Componentes Clave**

1. **EventDispatcher:** Clase central que gestiona la suscripción y el despacho de eventos.
2. **Subscribe**: Método para suscribir manejadores de eventos a eventos específicos.
3. **Unsubscribe**: Método para desuscribir manejadores de eventos.
4. **DispatchEvent**: Método que despacha eventos a todos los suscriptores registrados.
5. **EventDispatched**: Evento global que se dispara cada vez que se despacha un evento.

**Diseño de la Clase `EventDispatcher`**

La clase **EventDispatcher** actúa como el núcleo de la administración de eventos. Contiene métodos para suscribir y desuscribir manejadores, así como para despachar eventos. Internamente, mantiene un diccionario que asocia eventos con sus respectivos manejadores.

.. code-block:: csharp

    using System;
    using System.Collections.Generic;

    public class EventDispatcher
    {
        private readonly Dictionary<string, EventHandler> eventHandlers = new Dictionary<string, EventHandler>();

        public event EventHandler EventDispatched;

        public void Subscribe(string eventName, EventHandler eventHandler)
        {
            if (!eventHandlers.ContainsKey(eventName))
            {
                eventHandlers[eventName] = eventHandler;
            }
            else
            {
                eventHandlers[eventName] += eventHandler;
            }
        }

        public void Unsubscribe(string eventName, EventHandler eventHandler)
        {
            if (eventHandlers.ContainsKey(eventName))
            {
                eventHandlers[eventName] -= eventHandler;
            }
        }

        public void DispatchEvent(string eventName)
        {
            Console.WriteLine($"Evento '{eventName}' despachado.");
            EventDispatched?.Invoke(this, EventArgs.Empty);
            // Simulación de procesamiento
            Thread.Sleep(1000);
        }
    }

**Explicación del Código:**

* **Diccionario de Manejadores de Eventos:** Almacena los manejadores de eventos, utilizando el nombre del evento como clave.
* **Evento Global `EventDispatched`:** Permite una respuesta generalizada a todos los eventos despachados.
* **Método `Subscribe`:** Registra un manejador para un evento específico.
* **Método `Unsubscribe`:** Elimina un manejador de un evento específico.
* **Método `DispatchEvent`:** Desencadena un evento, notificando a los suscriptores y al evento global. Simula un procesamiento con un retardo.

**Suscripción y Desuscripción de Eventos**

Las clases externas interactúan con el despachador mediante los métodos `Subscribe` y `Unsubscribe` para gestionar sus suscripciones a eventos.

.. code-block:: csharp

    // Suscribir a un evento
    eventDispatcher.Subscribe("Evento1", Event1Handler);

    // Desuscribir un evento
    eventDispatcher.Unsubscribe("Evento1", Event1Handler);

**Manejo Global de Eventos**

El evento `EventDispatched` permite definir un manejador global que se ejecutará cada vez que se despache cualquier evento.

.. code-block:: csharp

    // Manejar el evento global
    eventDispatcher.EventDispatched += GlobalEventHandler;

**Simulación de Procesamiento de Eventos**

El método `DispatchEvent` incluye un retardo (`Thread.Sleep(1000)`) para simular el tiempo que podría tomar procesar un evento en un sistema real.

**El Bucle de Despacho de Eventos**

Aunque no está explícitamente presente en el código proporcionado, el concepto de un **bucle de despacho de eventos** es fundamental para entender cómo funciona este patrón de diseño. 

En un sistema de eventos real, existiría un bucle que constantemente verifica si hay eventos pendientes para ser despachados. Cuando un evento ocurre, el bucle lo toma de una cola de eventos y lo envía a todos los manejadores suscritos a ese evento.

En este código de ejemplo, la simulación del bucle se realiza de manera simplificada mediante el método `DispatchEvent`, que se llama manualmente desde el programa principal (`Main`). Sin embargo, en una aplicación real, el bucle de despacho se ejecutaría en segundo plano, esperando y procesando eventos de forma continua.

**Ejemplo Completo**

Se incluye un ejemplo completo que demuestra la creación de un `EventDispatcher`, la suscripción y desuscripción de eventos, el manejo global de eventos y el despacho de eventos.

.. code-block:: csharp

    using System;
    using System.Collections.Generic;
    using System.Threading;

    namespace EventDispatcher
    {
        public delegate void EventHandler(object sender, EventArgs e);

        public class EventDispatcher
        {
            private readonly Dictionary<string, EventHandler> eventHandlers = new Dictionary<string, EventHandler>();

            public event EventHandler EventDispatched;

            public void Subscribe(string eventName, EventHandler eventHandler)
            {
                if (!eventHandlers.ContainsKey(eventName))
                {
                    eventHandlers[eventName] = eventHandler;
                }
                else
                {
                    eventHandlers[eventName] += eventHandler;
                }
            }

            public void Unsubscribe(string eventName, EventHandler eventHandler)
            {
                if (eventHandlers.ContainsKey(eventName))
                {
                    eventHandlers[eventName] -= eventHandler;
                }
            }

            public void DispatchEvent(string eventName)
            {
                Console.WriteLine($"Evento '{eventName}' despachado.");
                EventDispatched?.Invoke(this, EventArgs.Empty);
                Thread.Sleep(1000);
            }
        }

        class Program
        {
            static void Main()
            {
                EventDispatcher eventDispatcher = new EventDispatcher();

                // Suscribir a un evento
                eventDispatcher.Subscribe("Evento1", Event1Handler);

                // Suscribir a un evento diferente
                eventDispatcher.Subscribe("Evento2", Event2Handler);

                // Manejar el evento global
                eventDispatcher.EventDispatched += GlobalEventHandler;

                // Despachar eventos
                eventDispatcher.DispatchEvent("Evento1");
                eventDispatcher.DispatchEvent("Evento2");

                // Desuscribir un evento
                eventDispatcher.Unsubscribe("Evento1", Event1Handler);

                // Despachar eventos nuevamente
                eventDispatcher.DispatchEvent("Evento1");
                eventDispatcher.DispatchEvent("Evento2");
            }

            static void Event1Handler(object sender, EventArgs e)
            {
                Console.WriteLine("Manejador del Evento1");
            }

            static void Event2Handler(object sender, EventArgs e)
            {
                Console.WriteLine("Manejador del Evento2");
            }

            static void GlobalEventHandler(object sender, EventArgs e)
            {
                Console.WriteLine("Manejador Global del Evento");
            }
        }
    }


**Conclusión**

Este código proporciona una implementación básica pero funcional de un despachador de eventos en C#, ilustrando los conceptos clave de suscripción, despacho y manejo de eventos, incluyendo la capacidad de tener un manejador global. Aunque el bucle de despacho está simulado de forma simplificada, el código captura la esencia de este patrón de diseño.

**Puntos a Considerar**

* **Escalabilidad:** Para sistemas más complejos, se podrían requerir optimizaciones en el almacenamiento y la búsqueda de manejadores.
* **Manejo de Errores:** El código actual no incluye manejo de errores, lo cual sería importante en una aplicación real.
* **Tipos de Eventos:** El ejemplo utiliza un tipo de evento genérico (`EventHandler`), pero en aplicaciones reales, se podrían definir eventos personalizados con datos específicos.
