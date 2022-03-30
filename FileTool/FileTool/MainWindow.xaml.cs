using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace FileTool
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string inputtFolder = string.Empty;
        private string outputFolder = string.Empty;
        private bool taskResult = true;


        public MainWindow()
        {
            InitializeComponent();
        }

        private async void btnStartExtract_Click(object sender, RoutedEventArgs e)
        {
            if (!Directory.Exists(tbInputFolder.Text)){
                lbStatus.Content = "Input folder is not exists !";
                return;
            }

            inputtFolder = tbInputFolder.Text;
            outputFolder = tbInputFolder.Text;

            if (cbOutput.IsChecked == true)
            {
                if (!Directory.Exists(tbOutputFolder.Text))
                {
                    lbStatus.Content = "Output folder is not exists !";
                    return;
                }

                outputFolder = tbOutputFolder.Text;
            }

            bool isOverwrite = cbOverWrite.IsChecked == true;
            var task_extract = CreateThreadExtract(cbOverWrite.IsChecked == true, cbFolder.IsChecked == true, tbAFilePattern.Text);
            bool[] results = await Task.WhenAll(task_extract);

            lbStatus.Content = results[0] ? "Success" : "Failed";
            Console.WriteLine($"finised {results[0]}");

        }


        private async Task<bool> CreateThreadExtract(bool isOverwrite, bool isExtractFileName, string filenamePattern)
        {
            await Task.Run(() => ThreadExtract(isOverwrite, isExtractFileName, filenamePattern));
            //Console.WriteLine("Task finished");
            return taskResult;
        }

        //read data thread
        private void ThreadExtract(bool isOverwrite, bool isExtractFileName, string filenamePattern)
        {
            taskResult = true;

            string opt = isOverwrite ? "-y x " : "x ";
            string cmdrun = string.Empty;
            


            string[] formats = { ".7z", ".zip"};
            foreach (string file in Directory.EnumerateFiles(inputtFolder, "*.*", SearchOption.AllDirectories).Where(x => formats.Any(x.EndsWith)))
            {
                // TODO...
                //Console.WriteLine($"{file}");

                if (!string.IsNullOrWhiteSpace(filenamePattern))
                {
                    string fname = System.IO.Path.GetFileNameWithoutExtension(file);
                    if (!fname.Contains(filenamePattern)) continue;
                }

                string filefolder = System.IO.Path.GetDirectoryName(file);
                string ofolder = !isExtractFileName ? filefolder : System.IO.Path.Combine(filefolder, System.IO.Path.GetFileNameWithoutExtension(file));

                ofolder = ofolder.Replace(inputtFolder, outputFolder);
                cmdrun = opt + $"\"{file}\" -o\"{ofolder}\"";

                Dispatcher.BeginInvoke(new Action(() =>
                {
                    //update to UI here
                    //lbStatus.Content = $"Extracting ....{file}";
                }), DispatcherPriority.Background);


                Console.WriteLine(cmdrun);
                taskResult = Run7z(cmdrun);
                if (!taskResult) return;
            }


        }

        public bool Run7z(string InstallArgs)
        {
            System.Diagnostics.Process myapp = new System.Diagnostics.Process();
            myapp.StartInfo.FileName = @"C:\Program Files\7-Zip\7z.exe";
            myapp.StartInfo.Arguments = InstallArgs;
            myapp.Start();
            myapp.WaitForExit();
            return (myapp.ExitCode == 0) ? true : false;
        }

    }
}
