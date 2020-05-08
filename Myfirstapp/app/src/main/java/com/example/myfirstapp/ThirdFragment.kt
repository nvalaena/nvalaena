package com.example.myfirstapp

import android.os.Bundle
import android.view.*
import android.widget.Button
import androidx.fragment.app.Fragment
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.fragment.findNavController
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class ThirdFragment : Fragment()  {
    private lateinit var patientViewModel: PatientViewModel

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        patientViewModel = ViewModelProvider(this).get(PatientViewModel::class.java)
        return inflater.inflate(R.layout.fragment_third, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val recyclerView = view.findViewById<RecyclerView>(R.id.recyclerview)
        val adapter = PatientListAdapter(view.context, patientViewModel)
        recyclerView.adapter = adapter
        recyclerView.layoutManager = LinearLayoutManager(view.context)

        patientViewModel = ViewModelProvider(this).get(PatientViewModel::class.java)

        patientViewModel.allPatients.observe(viewLifecycleOwner, Observer { patients ->
            // Update the cached copy of the words in the adapter.
            patients?.let { adapter.setPatient(it) }
        })
        view.findViewById<Button>(R.id.button_to_first).setOnClickListener {
            findNavController().navigate(R.id.action_ThirdFragment_to_FirstFragment)
        }
    }
}