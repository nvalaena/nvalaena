package com.example.myfirstapp

import android.app.DatePickerDialog
import android.app.DatePickerDialog.OnDateSetListener
import android.app.Dialog
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.DatePicker
import android.widget.Spinner
import android.widget.TextView
import androidx.fragment.app.DialogFragment
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.fragment.findNavController
import kotlinx.android.synthetic.main.fragment_second.*
import java.text.SimpleDateFormat
import java.util.*


/**
 * A simple [Fragment] subclass as the second destination in the navigation.
 */
class SecondFragment : Fragment() {
    private lateinit var patientViewModel: PatientViewModel

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        patientViewModel = ViewModelProvider(this).get(PatientViewModel::class.java)

        return inflater.inflate(R.layout.fragment_second, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        view.findViewById<Button>(R.id.button_second).setOnClickListener {
            findNavController().navigate(R.id.action_SecondFragment_to_FirstFragment)
        }
        val myCalendar = Calendar.getInstance();
        val date =
            OnDateSetListener { view, year, monthOfYear, dayOfMonth ->
                myCalendar.set(Calendar.YEAR, year)
                myCalendar.set(Calendar.MONTH, monthOfYear)
                myCalendar.set(Calendar.DAY_OF_MONTH, dayOfMonth)
                val myFormat = "MM/dd/yy" //In which you need put here

                val sdf = SimpleDateFormat(myFormat, Locale.US)

                input_record_date.setText(sdf.format(myCalendar.time))
            }
        input_record_date.setOnClickListener { v: View ->
            DatePickerDialog(
                    requireContext(), date, myCalendar[Calendar.YEAR], myCalendar[Calendar.MONTH],
                    myCalendar[Calendar.DAY_OF_MONTH]
            ).show()
        }

        save_button.setOnClickListener { v: View ->

            val sexSpinner = view.findViewById<Spinner>(R.id.sexSpinner)
            val name = input_name.text.toString()
            val familyName = input_family_name.text.toString()
            val lastName = input_last_name.text.toString()
            val height = input_height.text.toString()
            val weight = input_weight.text.toString()
            val numberProcedure = input_procedure_number.text.toString()
            val dataRecord = input_record_date.text.toString()
            val sex = sexSpinner.selectedItem.toString()

            val patient = Patient(
                name,
                lastName,
                familyName,
                sex,
                height,
                weight,
                dataRecord,
                numberProcedure
            )

            patientViewModel.insert(patient)
        }
        view.findViewById<Button>(R.id.button_database).setOnClickListener {
            findNavController().navigate(R.id.action_SecondFragment_to_ThirdFragment)
        }
    }

    fun showDatePickerDialog(v: View) {
        DatePickerFragment().show(parentFragmentManager, "datePicker")
    }

    inner class DatePickerFragment : DialogFragment(), DatePickerDialog.OnDateSetListener {
        override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {
            val c = Calendar.getInstance()
            val year = c.get(Calendar.YEAR)
            val month = c.get(Calendar.MONTH)
            val day = c.get(Calendar.DAY_OF_MONTH)

            // Create a new instance of DatePickerDialog and return it
            return DatePickerDialog(requireContext(), this, year, month, day)
        }

        override fun onDateSet(view: DatePicker, year: Int, month: Int, day: Int) {
            input_record_date.setText(java.sql.Date(year, month, day).toString())
        }
    }
}
