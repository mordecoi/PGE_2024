namespace SistemaGestionPersonas
{
    partial class ventana1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.glayout = new System.Windows.Forms.TableLayoutPanel();
            this.btnAgregarEstudiante = new System.Windows.Forms.Button();
            this.btnAgregarTrabajador = new System.Windows.Forms.Button();
            this.btnMostrarEmpleados = new System.Windows.Forms.Button();
            this.btnSalir = new System.Windows.Forms.Button();
            this.btnAgregarEmpleado = new System.Windows.Forms.Button();
            this.glayout.SuspendLayout();
            this.SuspendLayout();
            // 
            // glayout
            // 
            this.glayout.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.glayout.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.glayout.ColumnCount = 3;
            this.glayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.glayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.glayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.glayout.Controls.Add(this.btnAgregarEstudiante, 1, 0);
            this.glayout.Controls.Add(this.btnAgregarTrabajador, 2, 0);
            this.glayout.Controls.Add(this.btnMostrarEmpleados, 0, 1);
            this.glayout.Controls.Add(this.btnSalir, 2, 1);
            this.glayout.Controls.Add(this.btnAgregarEmpleado, 0, 0);
            this.glayout.Location = new System.Drawing.Point(12, 12);
            this.glayout.Name = "glayout";
            this.glayout.RowCount = 2;
            this.glayout.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.glayout.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.glayout.Size = new System.Drawing.Size(600, 417);
            this.glayout.TabIndex = 0;
            // 
            // btnAgregarEstudiante
            // 
            this.btnAgregarEstudiante.AutoSize = true;
            this.btnAgregarEstudiante.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnAgregarEstudiante.Location = new System.Drawing.Point(202, 3);
            this.btnAgregarEstudiante.Name = "btnAgregarEstudiante";
            this.btnAgregarEstudiante.Size = new System.Drawing.Size(106, 23);
            this.btnAgregarEstudiante.TabIndex = 1;
            this.btnAgregarEstudiante.Text = "Agregar estudiante";
            this.btnAgregarEstudiante.UseVisualStyleBackColor = true;
            this.btnAgregarEstudiante.Click += new System.EventHandler(this.btnAgregarEstudiante_Click);
            // 
            // btnAgregarTrabajador
            // 
            this.btnAgregarTrabajador.AutoSize = true;
            this.btnAgregarTrabajador.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnAgregarTrabajador.Location = new System.Drawing.Point(401, 3);
            this.btnAgregarTrabajador.Name = "btnAgregarTrabajador";
            this.btnAgregarTrabajador.Size = new System.Drawing.Size(104, 23);
            this.btnAgregarTrabajador.TabIndex = 2;
            this.btnAgregarTrabajador.Text = "Agregar trabajador";
            this.btnAgregarTrabajador.UseVisualStyleBackColor = true;
            this.btnAgregarTrabajador.Click += new System.EventHandler(this.btnAgregarTrabajador_Click);
            // 
            // btnMostrarEmpleados
            // 
            this.btnMostrarEmpleados.AutoSize = true;
            this.btnMostrarEmpleados.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnMostrarEmpleados.Location = new System.Drawing.Point(3, 211);
            this.btnMostrarEmpleados.Name = "btnMostrarEmpleados";
            this.btnMostrarEmpleados.Size = new System.Drawing.Size(151, 23);
            this.btnMostrarEmpleados.TabIndex = 3;
            this.btnMostrarEmpleados.Text = "Mostrar todos los empleados";
            this.btnMostrarEmpleados.UseVisualStyleBackColor = true;
            this.btnMostrarEmpleados.Click += new System.EventHandler(this.btnMostrarEmpleados_Click);
            // 
            // btnSalir
            // 
            this.btnSalir.AutoSize = true;
            this.btnSalir.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnSalir.Location = new System.Drawing.Point(401, 211);
            this.btnSalir.Name = "btnSalir";
            this.btnSalir.Size = new System.Drawing.Size(37, 23);
            this.btnSalir.TabIndex = 4;
            this.btnSalir.Text = "Salir";
            this.btnSalir.UseVisualStyleBackColor = true;
            this.btnSalir.Click += new System.EventHandler(this.btnSalir_Click);
            // 
            // btnAgregarEmpleado
            // 
            this.btnAgregarEmpleado.AutoSize = true;
            this.btnAgregarEmpleado.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnAgregarEmpleado.Location = new System.Drawing.Point(3, 3);
            this.btnAgregarEmpleado.Name = "btnAgregarEmpleado";
            this.btnAgregarEmpleado.Size = new System.Drawing.Size(103, 23);
            this.btnAgregarEmpleado.TabIndex = 0;
            this.btnAgregarEmpleado.Text = "Agregar empleado";
            this.btnAgregarEmpleado.UseVisualStyleBackColor = true;
            this.btnAgregarEmpleado.Click += new System.EventHandler(this.btnAgregarEmpleado_Click);
            // 
            // ventana1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.ClientSize = new System.Drawing.Size(624, 441);
            this.Controls.Add(this.glayout);
            this.Name = "ventana1";
            this.Text = "Gestor de personas";
            this.glayout.ResumeLayout(false);
            this.glayout.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel glayout;
        private System.Windows.Forms.Button btnAgregarEmpleado;
        private System.Windows.Forms.Button btnAgregarEstudiante;
        private System.Windows.Forms.Button btnAgregarTrabajador;
        private System.Windows.Forms.Button btnMostrarEmpleados;
        private System.Windows.Forms.Button btnSalir;
    }
}

