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
    public enum ECMD
    {
        EXTRACT = 0,
        COPY,
        MOVE,
        DELETE
    }

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private Properties.Settings appSettings = Properties.Settings.Default;
        private string outputFolder = string.Empty;
        private bool taskResult = true;

        public MainWindow()
        {
            InitializeComponent();
        }

        #region Settings
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //load setting
            //common
            tbInputFolder.Text = appSettings.common_input_folder;
            tbFilePattern.Text = appSettings.common_file_name_pattern;
            tbFileExtension.Text = appSettings.common_file_extension;
            tbOutputFolder.Text = appSettings.common_output_folder;

            //Extractor tab
            cbEnableOutputFolder.IsChecked = appSettings.common_enable_output_folder;
            cbOverWrite.IsChecked = appSettings.extractor_overwrite;
            cbExtractToFilenameFolder.IsChecked = appSettings.extractor_extract_to_filename_folder;
            cbDeleteFileAfterDone.IsChecked = appSettings.extractor_delete_after_extract;
            cbSubFolder.IsChecked = appSettings.common_include_subfolder;

            //File tab
            cbOverWriteCopy.IsChecked = appSettings.file_overwrite;
            rbTargetAll.IsChecked = appSettings.file_all_file;
            rbTargetSpecialFileExtensionOnly.IsChecked = appSettings.file_special_file_extension_only;
            rbTargetOtherThanSpecial.IsChecked = appSettings.file_other_than_special_ext_file;
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            //save
            UpdateSettings();
            appSettings.Save();
        }
        private void UpdateSettings()
        {
            //save setting
            appSettings.common_input_folder = tbInputFolder.Text;
            appSettings.common_output_folder = tbOutputFolder.Text;
            appSettings.common_file_name_pattern = tbFilePattern.Text;
            appSettings.common_file_extension = tbFileExtension.Text;
            appSettings.common_enable_output_folder = cbEnableOutputFolder.IsChecked == true;
            appSettings.common_include_subfolder = cbSubFolder.IsChecked == true;

            //Extractor tab
            appSettings.extractor_overwrite = cbOverWrite.IsChecked == true;
            appSettings.extractor_extract_to_filename_folder = cbExtractToFilenameFolder.IsChecked == true;
            appSettings.extractor_delete_after_extract = cbDeleteFileAfterDone.IsChecked == true;

            //File tab
            appSettings.file_overwrite = cbOverWriteCopy.IsChecked == true;
            appSettings.file_all_file = rbTargetAll.IsChecked == true;
            appSettings.file_special_file_extension_only = rbTargetSpecialFileExtensionOnly.IsChecked == true;
            appSettings.file_other_than_special_ext_file = rbTargetOtherThanSpecial.IsChecked == true;
        }
        private bool CheckSettings()
        {
            //check input folder
            if (!Directory.Exists(tbInputFolder.Text))
            {
                lbStatus.Content = "Input folder is not exists !";
                return false;
            }

            //check output folder
            outputFolder = tbInputFolder.Text;
            if (cbEnableOutputFolder.IsChecked == true)
            {
                if (!Directory.Exists(tbOutputFolder.Text))
                {
                    lbStatus.Content = "Output folder is not exists !";
                    return false;
                }

                outputFolder = tbOutputFolder.Text;
            }

            //check file extension
            if (funcTabExtractor.IsSelected
                || rbTargetSpecialFileExtensionOnly.IsChecked == true
                || rbTargetOtherThanSpecial.IsChecked == true)
            {
                List<string> reformatext = new List<string>();
                string[] fileext = tbFileExtension.Text.Split(' ');
                foreach (string ext in fileext)
                {
                    if (!string.IsNullOrWhiteSpace(ext))
                    {

                        if (ext.Substring(0, 1) != ".")
                        {
                            reformatext.Add("." + ext);
                        }
                        else
                        {
                            reformatext.Add(ext);
                        }
                    }
                }

                if (reformatext.Count == 0)
                {
                    lbStatus.Content = "File extension invalid !";
                    return false;
                }

                fileext = reformatext.ToArray();
                tbFileExtension.Text = string.Empty;
                foreach (string ext in fileext)
                {
                    tbFileExtension.Text += ext + " ";
                }

                tbFileExtension.Text = tbFileExtension.Text.Trim();
            }

            //re-format folder path
            tbInputFolder.Text = ReFormatFolderPath(tbInputFolder.Text);
            tbOutputFolder.Text = ReFormatFolderPath(tbOutputFolder.Text);

            //all OK
            return true;
        }
        private string ReFormatFolderPath(string fpath)
        {
            return string.IsNullOrWhiteSpace(fpath)
                ? fpath
                : System.IO.Path.Combine(System.IO.Path.GetDirectoryName(fpath), System.IO.Path.GetFileName(fpath));
        }
        #endregion

        #region UI
        private void CtrltabFunc_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (e.Source is TabControl) //if this event fired from TabControl then enter
            {
                if (funcTabExtractor.IsSelected)
                {
                    //Do your job here
                }
                else if (funcTabFile.IsSelected)
                {
                    //Do your job here
                }
            }
        }
        private void CbEnableOutputFolder_Checked(object sender, RoutedEventArgs e)
        {
            tbOutputFolder.IsEnabled = cbEnableOutputFolder.IsChecked == true;
        }
        #endregion

        #region Thread
        private async Task<bool> CreateThread(ECMD cmd)
        {
            if (cmd == ECMD.EXTRACT)
            {
                await Task.Run(() => ThreadExtract());
            }
            else if (cmd == ECMD.COPY || cmd == ECMD.MOVE || cmd == ECMD.DELETE)
            {
                await Task.Run(() => ThreadFile(cmd));
            }
            else
            {
                return false;
            }

            return taskResult;
        }
        #endregion

        #region Extractor tab
        private async void BtnStartExtract_Click(object sender, RoutedEventArgs e)
        {
            if (!CheckSettings()) return;
            UpdateSettings();

            //disable button
            btnStartExtract.IsEnabled = false;
            lbStatus.Content = "Processing ...";

            //start thread
            var task_extract = CreateThread(ECMD.EXTRACT);
            bool[] results = await Task.WhenAll(task_extract);

            //enable button
            btnStartExtract.IsEnabled = true;
            lbStatus.Content = results[0] ? "Success" : "Failed";
        }
        private void ThreadExtract()
        {
            taskResult = true;

            string opt = appSettings.extractor_overwrite ? "-y x " : "x ";
            string cmdrun = string.Empty;

            SearchOption searchType = appSettings.common_include_subfolder ? SearchOption.AllDirectories : SearchOption.TopDirectoryOnly;
            string[] formats = appSettings.common_file_extension.Split(' ');
            foreach (string file in Directory.EnumerateFiles(appSettings.common_input_folder, "*.*", searchType).Where(x => formats.Any(x.EndsWith)))
            {
                if (!string.IsNullOrWhiteSpace(appSettings.common_file_name_pattern))
                {
                    string fname = System.IO.Path.GetFileNameWithoutExtension(file);
                    if (!fname.Contains(appSettings.common_file_name_pattern)) continue;
                }

                string filefolder = System.IO.Path.GetDirectoryName(file);
                string ofolder = !appSettings.extractor_extract_to_filename_folder ? filefolder : System.IO.Path.Combine(filefolder, System.IO.Path.GetFileNameWithoutExtension(file));

                Console.WriteLine($"1ofolder={ofolder}");
                ofolder = ofolder.Replace(appSettings.common_input_folder, outputFolder);
                cmdrun = opt + $"\"{file}\" -o\"{ofolder}\"";

                //Dispatcher.BeginInvoke(new Action(() =>
                //{
                //    //update to UI here
                //    //lbStatus.Content = $"Extracting ....{file}";
                //}), DispatcherPriority.Background);


                Console.WriteLine(cmdrun);
                taskResult = Run7z(cmdrun);

                //delete if need
                if (taskResult && appSettings.extractor_delete_after_extract)
                {
                    File.Delete(file);
                }

                //return if NG
                if (!taskResult)
                {
                    return;
                }
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
        #endregion

        #region File tab
        private async void BtnFile_Click(object sender, RoutedEventArgs e)
        {
            if (!CheckSettings()) return;
            UpdateSettings();

            Button btn = (Button)sender;

            ECMD cmd = btn.Name == "btnCopyFile" ? ECMD.COPY : (btn.Name == "btnMoveFile" ? ECMD.MOVE : ECMD.DELETE);


            //disable button
            btnCopyFile.IsEnabled = false;
            btnMoveFile.IsEnabled = false;
            btnDeleteFile.IsEnabled = false;
            lbStatus.Content = "Processing ...";

            //start thread
            var task_extract = CreateThread(cmd);
            bool[] results = await Task.WhenAll(task_extract);

            //enable button
            btnCopyFile.IsEnabled = true;
            btnMoveFile.IsEnabled = true;
            btnDeleteFile.IsEnabled = true;
            lbStatus.Content = results[0] ? "Success" : "Failed";
        }
        private void ThreadFile(ECMD cmd)
        {
            Console.WriteLine($"ThreadFile={cmd}");
            taskResult = true;

            try
            {
                SearchOption searchType = appSettings.common_include_subfolder ? SearchOption.AllDirectories : SearchOption.TopDirectoryOnly;
                string[] formats = appSettings.common_file_extension.Split(' ');

                string[] fileList;
                if (appSettings.file_special_file_extension_only)
                {
                    fileList = Directory.EnumerateFiles(appSettings.common_input_folder, "*.*", searchType).Where(x => formats.Any(x.EndsWith)).ToArray();
                }
                else if (appSettings.file_other_than_special_ext_file)
                {
                    fileList = Directory.EnumerateFiles(appSettings.common_input_folder, "*.*", searchType).Where(x => !formats.Any(x.EndsWith)).ToArray();
                }
                else
                {
                    fileList = Directory.EnumerateFiles(appSettings.common_input_folder, "*.*", searchType).ToArray();
                }

                foreach (string file in fileList)
                {
                    if (!string.IsNullOrWhiteSpace(appSettings.common_file_name_pattern))
                    {
                        string fname = System.IO.Path.GetFileNameWithoutExtension(file);
                        if (!fname.Contains(appSettings.common_file_name_pattern)) continue;
                    }

                    string srcFile = file;
                    string desFile = srcFile.Replace(appSettings.common_input_folder, outputFolder);
                    Console.WriteLine(srcFile + " -> " + desFile);

                    if (cmd == ECMD.DELETE)
                    {
                        File.Delete(srcFile);
                    }
                    else if (cmd == ECMD.COPY)
                    {
                        if (srcFile.ToLower() == desFile.ToLower()) continue;
                        CreateFolder(desFile);
                        File.Copy(srcFile, desFile, appSettings.file_overwrite);
                    }
                    else if (cmd == ECMD.MOVE)
                    {
                        if (srcFile.ToLower() == desFile.ToLower()) continue;
                        CreateFolder(desFile);
                        File.Move(srcFile, desFile);
                    }

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
                taskResult = false;
            }
        }
        private bool CreateFolder(string filePath)
        {
            try
            {
                string folderPath = System.IO.Path.GetDirectoryName(filePath);
                if (!Directory.Exists(folderPath))
                {
                    Directory.CreateDirectory(folderPath);
                }
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
                return false;
            }
        }
        #endregion
    }
}
