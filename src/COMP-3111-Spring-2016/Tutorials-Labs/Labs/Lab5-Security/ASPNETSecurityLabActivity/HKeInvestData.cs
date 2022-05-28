using System;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;

namespace HKeInvestWebApplication.Code_File
{
    //**********************************************************
    //* THE CODE IN THIS CLASS CANNOT BE MODIFIED OR ADDED TO. *
    //*        Report problems to 3111rep@cse.ust.hk.          *
    //**********************************************************

    public class HKeInvestData
    {
        // Set the connection string to connect to the Enrollment database.
        SqlConnection HKeInvestDBConnection = new SqlConnection(ConfigurationManager.ConnectionStrings["HKeInvestConnectionString"].ConnectionString);

        // Process a SQL SELECT statement.
        public DataTable getData(string sql)
        {
            try
            {
                if (sql.Trim() == "")
                {
                    throw new ArgumentException("The SQL statement is empty.");
                }

                DataTable dt = new DataTable();
                if (HKeInvestDBConnection.State != ConnectionState.Open)
                {
                    HKeInvestDBConnection.Open();
                    SqlDataAdapter da = new SqlDataAdapter(sql, HKeInvestDBConnection);
                    da.Fill(dt);
                    HKeInvestDBConnection.Close();
                }
                else
                {
                    SqlDataAdapter da = new SqlDataAdapter(sql, HKeInvestDBConnection);
                    da.Fill(dt);
                }
                return dt;
            }
            catch (ArgumentException ex)
            {
                MessageBox.Show(ex.Message);
            }
   
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return null;
        }

        // Process an SQL SELECT statement that returns only a single value.
        // Returns 0 if the table is empty or the column has no values.
        public decimal getAggregateValue(string sql)
        {
            try
            {
                if (sql.Trim() == "")
                {
                    throw new ArgumentException("The SQL statement is empty.");
                }
                object aggregateValue;
                if (HKeInvestDBConnection.State != ConnectionState.Open)
                {
                    HKeInvestDBConnection.Open();
                    SqlCommand SQLCmd = new SqlCommand(sql, HKeInvestDBConnection);
                    SQLCmd.CommandType = CommandType.Text;
                    aggregateValue = SQLCmd.ExecuteScalar();
                    HKeInvestDBConnection.Close();
                }
                else
                {
                    SqlCommand SQLCmd = new SqlCommand(sql, HKeInvestDBConnection);
                    SQLCmd.CommandType = CommandType.Text;
                    aggregateValue = SQLCmd.ExecuteScalar();
                }
                return (DBNull.Value == aggregateValue ? 0 : Convert.ToDecimal(aggregateValue));
            }
            catch (ArgumentException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return -1;
        }

        // Process SQL INSERT, UPDATE and DELETE statements.
        public void setData(string sql, SqlTransaction trans)
        {
            try
            {
                if (sql.Trim() == "")
                {
                    throw new ArgumentException("The SQL statement is empty.");
                }

                SqlCommand SQLCmd = new SqlCommand(sql, HKeInvestDBConnection);
                SQLCmd.Transaction = trans;
                SQLCmd.CommandType = CommandType.Text;
                SQLCmd.ExecuteNonQuery();
            }
            catch (ArgumentException ex)
            {
                HKeInvestDBConnection.Close();
                MessageBox.Show(ex.Message);
            }
            catch (ApplicationException ex)
            {
                HKeInvestDBConnection.Close();
                MessageBox.Show(ex.Message);
            }
            catch (SqlException ex)
            {
                HKeInvestDBConnection.Close();
                MessageBox.Show(ex.Message);
            }
            catch (InvalidOperationException ex)
            {
                HKeInvestDBConnection.Close();
                MessageBox.Show(ex.Message);
            }
        }

        public SqlTransaction beginTransaction()
        {
            if (HKeInvestDBConnection.State != ConnectionState.Open)
            {
                HKeInvestDBConnection.Open();
                SqlTransaction trans = HKeInvestDBConnection.BeginTransaction();
                return trans;
            }
            else
            {
                SqlTransaction trans = HKeInvestDBConnection.BeginTransaction();
                return trans;
            }
        }

        public void commitTransaction(SqlTransaction trans)
        {
            try
            {
                if (HKeInvestDBConnection.State == ConnectionState.Open)
                {
                    trans.Commit();
                    HKeInvestDBConnection.Close();
                }
            }
            catch (ApplicationException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (InvalidOperationException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}