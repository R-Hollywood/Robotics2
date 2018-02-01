//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the joint_torque package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __joint_torque__JOINTSPRINGSEXAMPLECONFIG_H__
#define __joint_torque__JOINTSPRINGSEXAMPLECONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace joint_torque
{
  class JointSpringsExampleConfigStatics;
  
  class JointSpringsExampleConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(JointSpringsExampleConfig &config, const JointSpringsExampleConfig &max, const JointSpringsExampleConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const JointSpringsExampleConfig &config1, const JointSpringsExampleConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, JointSpringsExampleConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const JointSpringsExampleConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, JointSpringsExampleConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const JointSpringsExampleConfig &config) const = 0;
      virtual void getValue(const JointSpringsExampleConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T JointSpringsExampleConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (JointSpringsExampleConfig::* field);

      virtual void clamp(JointSpringsExampleConfig &config, const JointSpringsExampleConfig &max, const JointSpringsExampleConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const JointSpringsExampleConfig &config1, const JointSpringsExampleConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, JointSpringsExampleConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const JointSpringsExampleConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, JointSpringsExampleConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const JointSpringsExampleConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const JointSpringsExampleConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, JointSpringsExampleConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, JointSpringsExampleConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<JointSpringsExampleConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(JointSpringsExampleConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("s0_spring_stiffness"==(*_i)->name){s0_spring_stiffness = boost::any_cast<double>(val);}
        if("s0_damping_coefficient"==(*_i)->name){s0_damping_coefficient = boost::any_cast<double>(val);}
        if("s1_spring_stiffness"==(*_i)->name){s1_spring_stiffness = boost::any_cast<double>(val);}
        if("s1_damping_coefficient"==(*_i)->name){s1_damping_coefficient = boost::any_cast<double>(val);}
        if("e0_spring_stiffness"==(*_i)->name){e0_spring_stiffness = boost::any_cast<double>(val);}
        if("e0_damping_coefficient"==(*_i)->name){e0_damping_coefficient = boost::any_cast<double>(val);}
        if("e1_spring_stiffness"==(*_i)->name){e1_spring_stiffness = boost::any_cast<double>(val);}
        if("e1_damping_coefficient"==(*_i)->name){e1_damping_coefficient = boost::any_cast<double>(val);}
        if("w0_spring_stiffness"==(*_i)->name){w0_spring_stiffness = boost::any_cast<double>(val);}
        if("w0_damping_coefficient"==(*_i)->name){w0_damping_coefficient = boost::any_cast<double>(val);}
        if("w1_spring_stiffness"==(*_i)->name){w1_spring_stiffness = boost::any_cast<double>(val);}
        if("w1_damping_coefficient"==(*_i)->name){w1_damping_coefficient = boost::any_cast<double>(val);}
        if("w2_spring_stiffness"==(*_i)->name){w2_spring_stiffness = boost::any_cast<double>(val);}
        if("w2_damping_coefficient"==(*_i)->name){w2_damping_coefficient = boost::any_cast<double>(val);}
      }
    }

    double s0_spring_stiffness;
double s0_damping_coefficient;
double s1_spring_stiffness;
double s1_damping_coefficient;
double e0_spring_stiffness;
double e0_damping_coefficient;
double e1_spring_stiffness;
double e1_damping_coefficient;
double w0_spring_stiffness;
double w0_damping_coefficient;
double w1_spring_stiffness;
double w1_damping_coefficient;
double w2_spring_stiffness;
double w2_damping_coefficient;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double s0_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double s0_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double s1_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double s1_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double e0_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double e0_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double e1_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double e1_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w0_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w0_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w1_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w1_damping_coefficient;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w2_spring_stiffness;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double w2_damping_coefficient;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("JointSpringsExampleConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const JointSpringsExampleConfig &__max__ = __getMax__();
      const JointSpringsExampleConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const JointSpringsExampleConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const JointSpringsExampleConfig &__getDefault__();
    static const JointSpringsExampleConfig &__getMax__();
    static const JointSpringsExampleConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const JointSpringsExampleConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void JointSpringsExampleConfig::ParamDescription<std::string>::clamp(JointSpringsExampleConfig &config, const JointSpringsExampleConfig &max, const JointSpringsExampleConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class JointSpringsExampleConfigStatics
  {
    friend class JointSpringsExampleConfig;
    
    JointSpringsExampleConfigStatics()
    {
JointSpringsExampleConfig::GroupDescription<JointSpringsExampleConfig::DEFAULT, JointSpringsExampleConfig> Default("Default", "", 0, 0, true, &JointSpringsExampleConfig::groups);
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.s0_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.s0_spring_stiffness = 30.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.s0_spring_stiffness = 10.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s0_spring_stiffness", "double", 0, "s0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::s0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s0_spring_stiffness", "double", 0, "s0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::s0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.s0_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.s0_damping_coefficient = 10.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.s0_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s0_damping_coefficient", "double", 0, "s0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::s0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s0_damping_coefficient", "double", 0, "s0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::s0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.s1_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.s1_spring_stiffness = 30.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.s1_spring_stiffness = 15.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s1_spring_stiffness", "double", 0, "s1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::s1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s1_spring_stiffness", "double", 0, "s1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::s1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.s1_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.s1_damping_coefficient = 7.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.s1_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s1_damping_coefficient", "double", 0, "s1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::s1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("s1_damping_coefficient", "double", 0, "s1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::s1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.e0_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.e0_spring_stiffness = 15.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.e0_spring_stiffness = 5.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e0_spring_stiffness", "double", 0, "e0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::e0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e0_spring_stiffness", "double", 0, "e0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::e0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.e0_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.e0_damping_coefficient = 7.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.e0_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e0_damping_coefficient", "double", 0, "e0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::e0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e0_damping_coefficient", "double", 0, "e0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::e0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.e1_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.e1_spring_stiffness = 15.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.e1_spring_stiffness = 5.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e1_spring_stiffness", "double", 0, "e1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::e1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e1_spring_stiffness", "double", 0, "e1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::e1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.e1_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.e1_damping_coefficient = 5.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.e1_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e1_damping_coefficient", "double", 0, "e1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::e1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("e1_damping_coefficient", "double", 0, "e1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::e1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w0_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w0_spring_stiffness = 9.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w0_spring_stiffness = 3.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w0_spring_stiffness", "double", 0, "w0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w0_spring_stiffness", "double", 0, "w0 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w0_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w0_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w0_damping_coefficient = 1.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w0_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w0_damping_coefficient", "double", 0, "w0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w0_damping_coefficient", "double", 0, "w0 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w0_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w1_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w1_spring_stiffness = 4.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w1_spring_stiffness = 2.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w1_spring_stiffness", "double", 0, "w1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w1_spring_stiffness", "double", 0, "w1 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w1_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w1_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w1_damping_coefficient = 1.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w1_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w1_damping_coefficient", "double", 0, "w1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w1_damping_coefficient", "double", 0, "w1 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w1_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w2_spring_stiffness = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w2_spring_stiffness = 4.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w2_spring_stiffness = 1.5;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w2_spring_stiffness", "double", 0, "w2 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w2_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w2_spring_stiffness", "double", 0, "w2 - Joint spring stiffness (k). Hooke's Law.", "", &JointSpringsExampleConfig::w2_spring_stiffness)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.w2_damping_coefficient = 0.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.w2_damping_coefficient = 1.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.w2_damping_coefficient = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w2_damping_coefficient", "double", 0, "w2 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w2_damping_coefficient)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(JointSpringsExampleConfig::AbstractParamDescriptionConstPtr(new JointSpringsExampleConfig::ParamDescription<double>("w2_damping_coefficient", "double", 0, "w2 - Joint damping coefficient (c).", "", &JointSpringsExampleConfig::w2_damping_coefficient)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(JointSpringsExampleConfig::AbstractGroupDescriptionConstPtr(new JointSpringsExampleConfig::GroupDescription<JointSpringsExampleConfig::DEFAULT, JointSpringsExampleConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<JointSpringsExampleConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<JointSpringsExampleConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<JointSpringsExampleConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    JointSpringsExampleConfig __max__;
    JointSpringsExampleConfig __min__;
    JointSpringsExampleConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const JointSpringsExampleConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static JointSpringsExampleConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &JointSpringsExampleConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const JointSpringsExampleConfig &JointSpringsExampleConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const JointSpringsExampleConfig &JointSpringsExampleConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const JointSpringsExampleConfig &JointSpringsExampleConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<JointSpringsExampleConfig::AbstractParamDescriptionConstPtr> &JointSpringsExampleConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<JointSpringsExampleConfig::AbstractGroupDescriptionConstPtr> &JointSpringsExampleConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const JointSpringsExampleConfigStatics *JointSpringsExampleConfig::__get_statics__()
  {
    const static JointSpringsExampleConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = JointSpringsExampleConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __JOINTSPRINGSEXAMPLERECONFIGURATOR_H__
